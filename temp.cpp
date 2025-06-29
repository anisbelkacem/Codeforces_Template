// BELKA
#include <bits/stdc++.h>
#define ll long long int
#define unll unsigned long long
#define pb push_back
#define mp make_pair
#define f(i,j,k,l) for(ll i=j;i<k;i+=l)
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         affp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<" + ";cout<<endl;
#define all(v)  v.begin(),v.end()
#define rall(v)  v.rbegin(),v.rend()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

typedef unsigned long long ull;
typedef long double db;
using namespace std;
const ll P=1e8+5;
const ll MOD=1e9+7;
inline ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
const   int N=2e5+5;
// const   ll MOD = 998244353;
// vector<vector<pair<int,char>>> graph(n);
// vector<int> dp(n);
 
//  string s; 
// void dfs(int cur_node)
// {
//     if(graph[cur_node].size()==0)
//     {
//         return;
//     }
//     for(auto child_node : graph[cur_node])
//         {       
//             if(child_node.second != s[cur_node-1]) dp[child_node.first]=dp[cur_node]+1;
//             else dp[child_node.first]=dp[cur_node];
//             dfs(child_node.first);
 
 
//         }
// }
// string maxlex(string s)
// {
//     string mx="";
//     for(int i=0;i<s.size();i++)
//     {
//         mx=max(mx,s.substr(i));
//     }
//     return mx;
// }
bool prime(ll n) {
    if (n < 2) return false;
    for (ll x = 2; x*x <= n; x++) 
    {
       if (n%x == 0) return false;
    }
    return true;
}
 unll power(unll a, unll b)
{
    unll result = 1;
    while(b > 0)
    {
        if (b % 2 == 1)
        {
            result*= a;
            result%=MOD;
        }
        a *= a;
        a%=MOD;
        b /= 2;
    }
    return result%MOD;
}
map<int,int> primeFactors(ll n)
{
    map<int,int>mp;
    while (n%2 == 0)
    {
        mp[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
 
        while (n%i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }
 
    if (n > 2)
        mp[n]++;
    return mp;
}
int countNumBits1(ll mask) {   // O(bits Length)
    int ret = 0;    //1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
    while (mask) {
        if(mask&1)
            ret++;
        mask >>= 1;
    }
    return ret;
}
void printNumber(int n , string &s)
{
    if(! n ) return ;
    printNumber( n>>1 ,s);   // remove last bit
    // cout<<(n&1);
    if (n&1)s+='1';
    else s+='0';                        
}

ll sum(ll n)
{
    ll s=0;
    while(n!=0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
set<ll> divisors(ll n) {
    set<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
    if(n%i==0){
    ret.insert(i) ;
    ret.insert(n/i) ;
}
}
return ret;
}
 ll countp (ll a,ll b )
 {
    if ((a&1)!=(b&1))
    {
        return (b-a)/2;
    }
    else
    {
        if (a&1)
        {
            return (b-a)/2;
        }else
        {
            return (b-a)/2 +1 ;
        }

    }
 }
 ll countimp (ll a,ll b )
 {
    if ((a&1)!=(b&1))
    {
        return (b-a)/2;
    }
    else
    {
        if (a&1)
        {
            return ((b-a)/2 + 1);
        }else
        {
            return (b-a)/2;
        }

    }
 }
//for(int i=0;i<n;i++)
//=
auto comp= [](const auto &x, const auto &y) {
   if (x.first>y.first)return true;
   else if (x.first<y.first)return false;
   else
   {
        if(x.second<y.second)return true;
        else return false;
   }
};
auto comp1= [](const auto &x, const auto &y) {
   if (x.first<y.first)return true;
   else if (x.first>y.first)return false;
   else
   {
        if(x.second>y.second)return true;
        else return false;
   }
};
const int MAX = 200007;
ll tab[MAX];
void sumofdigittoN()
{
    for (int i = 1; i < MAX; i++) {
        tab[i]=tab[i-1] + sum(i);
    }
}
// const int p = 31; 
// const int m = 1e9 + 7;
// const int nh=1e6+5;
// ll H[nh];
// ll get_hash(string &s)
// {
//     ll h=0;
//     H[0]=1;
//     H[1]=(s[0]-'a'+1);
//     for(int i=1;i<(int)s.size();i++)
//     {
//         H[i+1]=(H[i]*31+(s[i]-'a'+1))%m;
//         h=H[i];
//     }
//     return h;

// }
long long lengthoflongestsubstirng(string st)
{
    //longest good substring which all caract are dif
    map<char,ll>count;
    ll s = 0;
    ll e=-1;
    ll n=st.length();
    ll ans=0;
    while(e<n)
    {
        // we can expand?
        if(s>e)
        {
            e++;
            count[st[e]]+=1;
            continue;
        }
        // do we have to shrink ?
        if (e==n-1)
        {
            ans=max(ans,e-s+1);
            if(s==n-1)break;
            count[st[s]]--;
            s++;
            continue;
        }
        // can we expand ?
        if(count[st[e+1]]==0)
        {
            e++;
            count[st[e]]++;
            continue;
        }else
        {
            ans=max(ans,e-s+1);
            count[st[s]]--;
            s++;
            continue;
        }
    } 
    return ans;
} 
vector<int> longestprefixsuffix(string s){
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

ll maxXorSum(const vector<ll>& a) {
    int n = a.size();
    vector<int> bitCount(31, 0);
    for (ll num : a) {
        for (int b = 0; b < 31; ++b) {
            if ((num >> b) & 1)
                bitCount[b]++;
        }
    }
    ll maxSum = 0;
    for (ll ak : a) {
        ll currSum = 0;
        for (int b = 0; b < 31; ++b) {
            ll bitVal = (1 << b);
            if ((ak >> b) & 1) {
                currSum += (n - bitCount[b]) * bitVal;
            } else {
                currSum += bitCount[b] * bitVal;
            }
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

void allSubsequences(string &input,set<string> &subsequences,string current = "", int index = 0) {
    if (index == input.length()) {
        subsequences.insert(current);
        return;
    }
    allSubsequences(input, subsequences, current + input[index], index + 1);
    allSubsequences(input, subsequences, current, index + 1);
}
int fact[N];
void work(){
    fact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}
ll binexp(ll a, ll k,ll mod=MOD){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}
ll inv(ll n){
    return binexp(n,MOD-2);
}
ll mul(ll u , ll v, ll mod=MOD){
    return ((u%mod)*(v%mod))%mod;
}
ll add(ll u, ll v, ll mod=MOD){
    return ((u%mod)+(v%mod)+mod)%mod;
}
 
ll sub(ll u, ll v , ll mod=MOD){
    return ((u%mod)-(v%mod)+mod)%mod;
}
ll Cnk(ll n,ll k){
    return mul(mul(fact[n],inv(fact[k])),inv(fact[n-k]));
}


int compa(string a,string b)
{
    if (a.size()!=b.size())return 10;
    else
    {
        int k=0;
        for (int i=0;i<(int)a.size();i++)
        {
            if(a[i]!=b[i])k++;
        }
        return k ;
    }
}

//==
void solve()
{
    
}  

//=
        



int main(){
       #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(false);cin.tie(0);
        int _=1;
        cin >>_;

        while(_--) { solve(); }
}
