/*
 Newton's method and Square root of n in C++
 C++によるニュートン法の実装と平方根√nの計算
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
double start,error;
//平方根の底をnで受け取る。
//初期値の入力をstartで受け取り、
//誤差限界の入力をerrorで受け取る。

//微分を実行する関数
pair<ll,ll> differentiate(pair<ll,ll> p){
    return {p.first*p.second,p.second-1};
}

//ニュートン法の反復計算を実行する関数
double newton(void){
    //√nを求める場合、
    //f(x)=x^2-nとおいてf(x)=0となる解を考える。
    //また、f'(x)=2*xである。
    double ans=start;
    double ans2=start-(start*start-n)/(2*start);
    while(abs(ans-ans2)>=error){
        ans=ans2;
        ans2=ans-(ans*ans-n)/(2*ans);
    }
    return ans2;
}

int main(void){
    cin>>n>>start>>error;
    cout<<fixed<<setprecision(30)<<
			newton()<<endl; //求まった近似値を出力
    return 0;
}
