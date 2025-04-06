#include<bits/stdc++.h>
using namespace std;
#define int int64_t


int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daySum(int mm){
    int days = 0;
    for(int  i = 1; i<mm; i++){
        days+=days_in_month[i];
    }
    return days;
}
int dateHash(int y, int m, int d){
    int hash = y * 365;
    hash+=daySum(m) + d;
    return hash;
}


string reverseDateHash(int hash) {
    int year = hash / 365;
    int dayOfYear = hash - year * 365;

    // If dayOfYear == 0, it's the last day of the previous year: Dec 31
    if (dayOfYear == 0) {
        year -= 1;
        return to_string(year) + "-12-31";
    }

    // Find the month
    int month = 1;
    while (month <= 12 && dayOfYear > days_in_month[month]) {
        dayOfYear -= days_in_month[month];
        month++;
    }

    int day = dayOfYear;

    // Format YYYY-MM-DD with leading zeros
    ostringstream oss;
    oss << setw(4) << setfill('0') << year << "-"
        << setw(2) << setfill('0') << month << "-"
        << setw(2) << setfill('0') << day;

    return oss.str();
}


vector<int> mark(3e6, 0);

void solve(){
    int n; cin>>n;
    int y, d; cin>>y>>d;
    vector<pair<int,int>> v;
    for(int i = 0; i<n; i++){
        string s;cin>>s;
        int year = stoi(s.substr(0, 4));
        int month = stoi(s.substr(5, 2));
        int day = stoi(s.substr(8, 2));
        int h1 = dateHash(year, month, day);
        cin>>s;
         year = stoi(s.substr(0, 4));
         month = stoi(s.substr(5, 2));
         day = stoi(s.substr(8, 2));
        int h2 = dateHash(year, month, day);
        v.push_back({h1, h2});
        mark[h1]++;
        mark[h2 + 1]--;
    }
    int sum = 0;
    for(int i = 1; i<=3e6; i++){
        sum+=mark[i];
        mark[i] = sum;
    }
    sum = 0;
    for(int i = 1; i<=3e6; i++){
        mark[i] += mark[i-1];
    }

    int startDate = v.back().second;
    for(int i = startDate; i<=(int)3e6; i++){
        int cnt = y;
        int st = i - y*365;
        while(st < i){
            int rng = mark[st + 364] - mark[st - 1];
            if(365 - rng < d){
                break;
            }
            st+=365;
        }
        if(st == i){
            cout<<reverseDateHash(i)<<endl;
            return;
        }
    }
    


    
    





}




int32_t main(){
    solve();
    exit(0);
}
