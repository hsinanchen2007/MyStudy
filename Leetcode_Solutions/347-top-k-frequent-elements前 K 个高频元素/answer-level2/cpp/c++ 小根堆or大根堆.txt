### 小根堆
1. 遍历数组，哈希表录入频率
2. 遍历哈希表，维护一个出现频率前k多的小根堆
3. 优先队列已满，需要判断当前元素的频率是否大于优先队列的最小频率元素的频率，如果大于，则替换。
4. 优先队列未满，进队即可

**注意**：c++ 优先队列默认大根堆，设置时需要`priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > >`实现小根堆。
<br/>

### 代码
```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> record;  //(元素，频率)
        //遍历数组，录入频率
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
        }
        int n = record.size();

        //扫描record。维护当前出现频率最多的k个元素
        //最小堆。如果当前元素的频率大于优先队列中最小频率元素的频率，则替换
        //优先队列中，按频率排序，所以数据对是(频率，元素)形式
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
        for(auto iter = record.begin(); iter != record.end(); iter++){
            if(k == pq.size()){ //队列已满
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
            }
            else{
                pq.push(make_pair(iter->second,iter->first));
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        //更正
        reverse(result.begin(), result.end());

        return result;
    }
};
```

<br/>
### 大根堆
通常情况下求前k大用小根堆，求前k小用大根堆。我们知道，小根堆的方法的时间复杂度为`O(nlogk)`，如果`k`与`n`很接近呢？如果我非要用大根堆呢？其实也是可以的，只是需要转换一下思路即可。既然让我们求前k大，那么我们是不是可以转换一下思路求前n-k小呢？当然是可以的，而且c++的堆默认是大根堆，这样会稍微省一下声明的麻烦。但最后两者的执行用时一样，哭了～～
<br/>
**注意**：一定要考虑`n == k`的情况，不然你就会像我一样卡在测试用例`nums = [1], k = 1`上，错误信息为`Char 17: runtime error: reference binding to null pointer of type 'const struct pair' (stl_iterator.h)`。其实很好理解：对于该测试用例，`n == k`会使得一开始`if( (n - k) == (int)pq.size() )`就通过，那么在初始条件下，就会进行**取堆顶**和**出堆**的操作，显然队列为空，不能访问。
<br/>
### 代码
```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         
        unordered_map<int,int> record;  //(元素，频率)
        //遍历数组，录入频率
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
        }
        int n = record.size();
         
        vector<int> result;
        if(n != k){ // 如果 n == k，根据题意，直接统计 record 中的元素就好了
             
            //扫描record。维护当前出现频率最少的n-k个元素
            //最大堆。如果当前元素的频率小于优先队列中最大频率元素的频率，则替换
            //优先队列中，按频率排序，所以数据对是(频率，元素)形式
            priority_queue< pair<int,int> > pq;
            for(auto iter = record.begin(); iter != record.end(); iter++){
                if((n - k) == (int)pq.size()){ //队列已满
                    if(iter->second < pq.top().first){
                        pq.pop();
                        pq.push(make_pair(iter->second,iter->first));
                    }
                }
                else{
                    pq.push(make_pair(iter->second,iter->first));
                }
            }
         
            while(!pq.empty()){
                record.erase(pq.top().second);
                pq.pop();
            }
        }
         
        for(auto iter : record){
            result.push_back(iter.first);
        }
        return result;
    }
};
```
<br/>

>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
>本人blog：<https://zhengguanyu.github.io>
