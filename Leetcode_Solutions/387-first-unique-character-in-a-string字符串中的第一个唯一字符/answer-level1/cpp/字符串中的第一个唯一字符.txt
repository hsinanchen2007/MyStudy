看到这道题,我的第一反应是遍历整个字符串,使用count()函数查找只出现一次的字母,就有了下面的代码:
```
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0)
			return -1;
		else if (s.size() == 1)
			return 0;
		else {
			int temp = -1;
			for (int i = 0; i < s.size(); i++) {
				if (count(s.begin(), s.end(), s[i]) == 1) {
					temp = i;
					break;
				}
			}
			return temp;
		}
    }
};
```
但是由于会出现像下面这种测试用例,如图:
![字母大小写全排列.png](https://pic.leetcode-cn.com/b5594c8aaf513d3f7ac46dc05e4c1d5f52aa5bd964151c9e0ef5a03b4c2fcebc-%E5%AD%97%E6%AF%8D%E5%A4%A7%E5%B0%8F%E5%86%99%E5%85%A8%E6%8E%92%E5%88%97.png)
导致我的算法直接炸掉,超出时间限制,我就想先剔除字符串中的重复项,即:
```
string tmp = s;
sort(tmp.begin(), tmp.end());
tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
```
然后寻找字符串tmp中只在字符串s中出现一次的字符,组成新字符串temp,最后再遍历s,使用find()函数,一旦s[j]出现在temp中,就是结果,那么完整代码如下
```
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0)
			return -1;
		else if (s.size() == 1)
			return 0;
		else {
			string tmp = s,temp="";
			sort(tmp.begin(), tmp.end());
			tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			int res = -1;
			string::size_type idx;
			for (unsigned int i = 0; i < tmp.size(); i++) {
				if (count(s.begin(), s.end(), tmp[i]) == 1) {
					temp += tmp[i];
				}
			}
			for (unsigned int j = 0; j < s.size(); j++) {
				idx = temp.find(s[j]);
				if (idx != string::npos) {
					res = j;
					break;
				}
			}
			return res;
		}
    }
};
```
在这里对于函数进行一下说明:
# 1. **unique()函数**
unique函数是一个去重函数，去除相邻中的重复元素（只留一个）。
其中，最关键的是：并不是删除并不是把重复的元素删除，而是全部放倒数组的后面。
因为，unique只是去除（相邻）的重复元素，因此，为了去除重复的元素，应该，首先对数组/Vector进行排序，这样保证重复元素在相邻的位置。
**unique函数，返回的是去重后的尾地址。**
因此对于一个内容为{2, 2, 5, 5, 6}的vector，执行unique函数以后，vector大小并没有改变，只不过顺序变成了{2, 5, 6, 2, 5}，并且函数的返回值为:3。
此时需要删除重复元素，只需要将后面的数据全部删除即可。

# 2. **find()函数**
C++的string类提供了字符串中查找另一个字符串的函数find。
其重载形式为：
```
string::size_type string::find(string &);
```
功能为在string对象中，查找参数string类型的字符串是否存在，如果存在，返回起始位置。不存在则返回 string::npos。