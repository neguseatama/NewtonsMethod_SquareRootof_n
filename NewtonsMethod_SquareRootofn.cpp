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



//ChatGPT
#include <iostream>
#include <cmath>

double newtonSqrt(double n, double initialGuess, double tolerance) {
    double x = initialGuess;  // 初期推定値
    double prevX = x;
    
    do {
        prevX = x;
        x = 0.5 * (x + n / x);  // ニュートン法の更新式
    } while (std::abs(x - prevX) > tolerance);  // 収束判定
    
    return x;
}

int main() {
    double n, initialGuess, tolerance;
    std::cout << "nを入力してください: ";
    std::cin >> n;
    std::cout << "初期値を入力してください: ";
    std::cin >> initialGuess;
    std::cout << "誤差の許容上限を入力してください: ";
    std::cin >> tolerance;
    
    double sqrtN = newtonSqrt(n, initialGuess, tolerance);
    std::cout << "ルート" << n << "の近似値: " << sqrtN << std::endl;
    
    return 0;
}