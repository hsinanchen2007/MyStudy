### 解题思路
//提交时存在的问题是存在多个出现次数相同的元素时，执行代码选取的元素和答案提供的不一致导致解答错误，但是桶排序的方法结果没有出错

### 代码

```cpp
class Solution {
public:
    //vector<pair<int,int>> heap;//最小堆
    //提交时存在的问题是存在多个出现次数相同的元素时，执行代码选取的元素和答案提供的不一致导致解答错误
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> maps;
        for(int i=0;i<nums.size();i++)
        {
            if(maps.find(nums[i])==maps.end())
            {
                maps.insert(make_pair(nums[i],1));
            }
            else
            {
                int times=maps.find(nums[i])->second;
                maps[nums[i]]=times+1;
            }
        }
        map<int,int>::iterator it;
        //使用桶排序
        vector<vector<int>> bucket(nums.size()+1);
        for(it=maps.begin();it!=maps.end();it++)
        {
           bucket[it->second].push_back(it->first);
        }
        vector<int> res(k,0);
        int index=0;
 //使用桶排序，将数据放到出现次数对应的桶之中
       for(int i=bucket.size()-1;i>=0;i--)
        {
            for(int j=0;j<bucket[i].size();j++)
            {
                if(index==k)
                    return res;
                res[index++]=bucket[i][j];
            }
        }
        return res;
    }
    /*
    ector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> maps;
        for(int i=0;i<nums.size();i++)
        {
            if(maps.find(nums[i])==maps.end())
            {
                maps.insert(make_pair(nums[i],1));
            }
            else
            {
                int times=maps.find(nums[i])->second;
                maps[nums[i]]=times+1;
            }
        }
        map<int,int>::iterator it;
        //使用自带的优先级队列--------最小堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(it=maps.begin();it!=maps.end();it++)
        {
            if(pq.size()!=k)
            {
                pq.push(make_pair(it->first,it->second));
                //swim(heap.size()-1);
            }
            else
            {
                if(pq.top().second<it->second)
                {
                    pq.pop();
                    pq.push(make_pair(it->first,it->second));
                }
            }
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
    */
    /*
    vector<pair<int,int>> heap;//构建最小堆
    int n;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> maps;
        for(int i=0;i<nums.size();i++)
        {
            if(maps.find(nums[i])==maps.end())
            {
                maps.insert(make_pair(nums[i],1));
            }
            else
            {
                int times=maps.find(nums[i])->second;
                maps[nums[i]]=times+1;
            }
        }
        map<int,int>::iterator it;
        heap.push_back(make_pair(-1,-1));//哨兵
        n=k+1;
        for(it=maps.begin();it!=maps.end();it++)
        {
            if(heap.size()!=n)
            {
                heap.push_back(make_pair(it->first,it->second));
                swim(heap.size()-1);
            }
            else
            {
                if(heap[1].second<it->second)
                {
                    heap[1]=make_pair(it->first,it->second);
                    sink(1);
                }
            }
        }
        vector<int> res;
        for(int i=n-1;i>=1;i--)
        {
            res.push_back(heap[i].first);
        }
        return res;
    }
    void swim(int k)
    {
        while(k>1)
        {
            if(heap[k/2].second<=heap[k].second)
                break;
            swap(k/2,k);
            k=k/2;
        }
    }
    void sink(int k)
    {
        while(2*k<=heap.size()-1)
        {
            int j=2*k;
            if((j<heap.size()-1)&&(heap[j].second>heap[j+1].second))
                j++;
            swap(j,k);
            k=j;
        }
    }
    void swap(int i,int j)
    {
        pair<int,int> tmp=heap[i];
        heap[i]=heap[j];
        heap[j]=tmp;
    }
    */
};
```