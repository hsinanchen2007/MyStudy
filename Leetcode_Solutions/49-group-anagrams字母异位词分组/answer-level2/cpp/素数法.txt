# 思路
这道题只是要求单词中字母排列一致就行，并没有顺序的要求（不需要按26进制来运算）。
这就可以用大家所说的素数法，将单词中每个字母对应 的素数相乘，就可以得到了该单词的key值，再将key值存入map中。
该map<double, int> map的键值（double）是用来保存每个单词相对应的值，而int的部分是用来表示该单词在所要返回数组中的索引值。 

# 举个例子：
返回数组 vector<vector<string>> res.  

素数表 int prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };

输入【"eat"， "tea"， "nat"】

先将"eat"的值计算出来， 结果是2002，由于map中没有键值为2002的信息，我们先创建一个vector<string> v, 并将 "eat"放入到v中，再将v放入res中，这时候v的索引值是0，因为它是第一个被放进去的， map键值为2002的地方放入值0.

再然后计算"tea", 它的结果也是2002，map中有键值为2002的信息，且该信息的值为0， 我们可以直接在res索引0 (也就是res[0]) 的位置放入"tea". 

最后计算"nat", 该结果为6106， map中没有键值为6106的信息，我们再创建一个vector<string> v, 并将 "nat"放入到v中，再将v放入res中，这时候res中本来存在一个元素，所以该v索引为1， map键值为6106的地方放入值1.

```
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<double, int> map;
        //int prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
        vector<int> prime;
        makePrime(prime, 1000);
        for(auto& str : strs) {
            double feature = 1;
            for(auto s : str)
                feature *= prime[s - 'a'];
            auto iter = map.find(feature);
            if(iter == map.end()) {
                vector<string> v{ str };
                res.push_back(v);
                map.insert(make_pair(feature, res.size() - 1));
            } else {
                auto i = iter->second;
                res[i].push_back(str);
            }
        }
        return res;
    }
//makePrime的用处是用来产生素数表，也可以直接将int prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 }拿来用
void makePrime(vector<int>& prime, int size) 
    {
        static vector<bool> vis(size, false);
        for(int i = 2; i <= size; ++i)
        {
            if(!vis[i]) prime.push_back(i);
            for(int j = 0; j < prime.size() && i * prime[j] <= size; ++j) {
                vis[i * prime[j]] = true;
                if(i % prime[j] == 0) break;
            }
        }
    }
```

# 