vector<int> vg[MAXN];
int mstack[MAXN], msize;
// st start time in dfs order
bool cmp(int u, int v) { return st[u] < st[v]; }
void build_tree(vector<int> vec){
	// vec nodes given in query
	if(vec.empty()) { vg[0].clear(); return; }
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int st_sz = vec.size();
	for(int i = 0; i + 1 < st_sz; i++)
		vec.push_back(lca(vec[i], vec[i + 1]));
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int vertex: vec)
		vg[vertex].clear();
	msize = 0;
	mstack[msize++] = vec[0];
	for(int i = 1; i < (int)vec.size(); i++){
		int anc = lca(mstack[msize - 1], vec[i]);
		if(anc != mstack[msize - 1]){
			while(msize > 1 && d[mstack[msize - 2]] >= d[anc]){
				vg[mstack[msize - 2]].push_back(mstack[msize - 1]);
				msize--;
			}
			if(anc != mstack[msize - 1]){
				vg[anc].push_back(mstack[msize - 1]);
				msize--; mstack[msize++] = anc;
			}
		}
 
		mstack[msize++] = vec[i];
	}
	for(int i = 0; i < msize - 1; i++)
		vg[mstack[i]].push_back(mstack[i + 1]);
	vg[0].clear(); vg[0].push_back(mstack[0]);
}