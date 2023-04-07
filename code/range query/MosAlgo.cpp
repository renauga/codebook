int block_size;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {   
        if(l/block_size != other.l/block_size)return make_pair(l , r) <
               make_pair(other.l , other.r);
        return (l/block_size & 1) ? (r < other.r) : (r > other.r);
    }
};