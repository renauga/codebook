#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//use only if code is very short
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure() auto end_time = std::chrono::high_resolution_clock::now(); cerr << (end_time - start_time)/std::chrono::milliseconds(1) << "ms" << endl;

typedef long long ll;

#ifndef ONLINE_JUDGE

template<typename T>
void __p(T a) {cout<<a;}

template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(vector<T> a) { //reuse for set and map
	cout<<"{";
	for(T i:a) __p(i),cout<<",";
    cout<<"}";
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names,',');
	cout.write(names,comma-names)<<" : ";
	__p(arg1);cout<<" | ";__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	return 0;
}