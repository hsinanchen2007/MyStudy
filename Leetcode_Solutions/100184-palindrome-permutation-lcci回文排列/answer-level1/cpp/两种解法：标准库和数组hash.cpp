本题的基本思路是统一的，就是出现的次数为奇数的字母数量不能大于1，最多一个。

第一种方法：map和set的运用，将字母都当做map和set的key，其中map中key的value是pair，保存的是出现次数和是否为奇数。
第二种：hash table，建立和总共48个字母一一对应的映射关系，然后看看奇数的元素是不是小于等于1

其实思路都是类似的思路，只是实现方法不同。用数组实现的hash table速度更快。

```
// 解法1
class Solution {
public:
    int hash[128] = {0};
	bool canPermutePalindrome(string s) {
        // for (int i = 0; i < 128; ++i) {
        //     hash[i] = 0;
        // }
		for (int i = 0; i < s.size(); ++i) {
			hash[s[i]]++;
		}
		int cnt = 0;
		for (int i = 0; i < 128; ++i) {
			if (hash[i] % 2 == 1)
				cnt++;
		}
		return (cnt <= 1);
	}

};

// 解法2
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, pair<int, int> > mem;
        set<char> dup;
        for (int i = 0; i < s.size(); ++i) {
            mem[s[i]].first++; // first restore the count of alph., second restore the feature of the alp..
            mem[s[i]].second =  mem[s[i]].first % 2;
            dup.insert(s[i]); // Add element into dup-set
        }
        
        int cnt = 0;
        for (int i = 0; i < dup.size(); ++i) { // 遍历set中的所有字符
            set<char>::iterator it = dup.begin();
            std::advance(it, i);
            char ch = *it;
            if (mem[ch].second)
                cnt++;
        }
        return cnt <= 1;
    }
};
```