# /*-------------------------------1------------------------------------*/
# /*将石头存为multiset，在set中查找宝石
执行用时：8ms    
内存消耗：8.6MB   */
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        multiset<char> stone;
        for(auto i:S)
            stone.insert(i);
        int num=0;
        for(auto j:J)
        {
            num+=stone.count(j);
        }
        return num;
    }
};
```
/*-------------------------------2------------------------------------*/
# /*将宝石存为multiset，在set中查找石头
执行用时：4ms    
内存消耗：8.6MB  */
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        multiset<char> stone;
        for(auto j:J)
            stone.insert(j);
        int num=0;
        for(auto i:S)
        {
            num+=stone.count(i);
        }
        return num;
    }
};
```



/*-------------------------------3------------------------------------*/
# /*采用string的find函数，找到便返回字符下标，找不到返回string的标记npos
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了77.49%的用户*/
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num=0;
        for(auto i:S)
        {
            if(J.find(i)!=J.npos)
                num++;
        }
        return num;
    }
};
```
我也不知道为什么最后一个速度这么快，应该是有问题(跟定不能0ms)，但整体比set快点，但
当数据量大时，应该set更快点。