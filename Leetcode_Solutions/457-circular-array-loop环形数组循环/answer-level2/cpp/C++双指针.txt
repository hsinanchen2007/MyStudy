1. 首先首先我们需要一个 visited 数组，来记录访问过的数字
2. 然后我们遍历原数组，如果当前数字已经访问过了，直接跳过，否则就以当前位置坐标为起始点开始查找，进行 while 循环，计算下一个位置（计算方法是当前位置坐标加上对应的数字，由于是循环数组，所以结果可能会超出数组的长度，所以我们要对数组长度取余。当然上面的数字也可能是负数，加完以后可能也是负数，所以在取余之前还得再补上一个n，使其变为正数，但是 若这个负数远大于n的话，取余之前只加上一个n，可能是不够的，所以正确的方法是应该先对n取余，再加上n。为了同时把正数的情况也包含进来，最终我们的处理方法是先对n取余，再加上n，再对n取余，这样不管正数还是负数，大小如何，都可以成功的旋转跳跃了。）
3. 此时我们判断，如果 next 和 cur 相等，说明此时是一个数字的循环，不符合题意，再有就是检查二者的方向，数字是正数表示 forward，若是负数表示 backward，在一个 loop 中必须同正或同负，我们只要让二者相乘，如果结果是负数的话，说明方向不同，直接 break 掉。此时如果 next 已经有映射了，说明我们找到了合法的 loop，返回 true，否则建立一个这样的映射，将 next 位置在 visited 数组中标记 true，继续循环。
```
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n);
        for(int i=0;i<n;i++)
        {
            if(visited[i]) continue;
            visited[i]=true;
            unordered_map<int,int> m;
            int cur=i;
            while(true)
            {
                int next=((cur+nums[cur])%n+n)%n;
                if(next==cur||nums[next]*nums[cur]<0)
                break;
                if(m.count(next)) return true;
                m[cur]=next;
                cur=next;
                visited[next]=true;
            }
        }
        return false;
    }
};

```

