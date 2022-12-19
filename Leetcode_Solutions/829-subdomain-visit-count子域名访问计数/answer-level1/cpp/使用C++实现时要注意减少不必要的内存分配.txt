要注意的点：
1. 不要用new
2. 不推荐用stringstream
3. 通过reserve减少内存重分配
4. 使用string_view而不是substr以避免内存分配
5. 充分利用好emplace接口和std::move

```
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map< string_view, int > url2count;
        url2count.reserve( cpdomains.size() * 3 );
        for( const auto& s : cpdomains ){
            const auto* const s_data= s.data();
            const auto s_size= s.size();
            size_t url_begin= 0;
            const auto count= stoi( s, &url_begin );
            char last= ' ';
            for( ; url_begin<s.size(); ++url_begin ){
                const auto c= s[url_begin];
                if( c != ' ' && c != '.' && ( last == ' ' || last == '.' ) ){
                    const string_view url( s_data + url_begin, s_size - url_begin );
                    const auto itor= url2count.find( url );
                    if( itor == url2count.end() ){
                        url2count.emplace( url, count );
                    }else{
                        itor->second += count;
                    }
                }
                last= c;
            }
        }
        vector< string > result;
        result.reserve( url2count.size() );
        for( const auto& data : url2count ){
            string s;
            s.reserve( data.first.size() + 8 );
            s += to_string( data.second );
            s += ' ';
            s += data.first;
            result.emplace_back( move( s ) );
        }
        return result;
    }
};
```

