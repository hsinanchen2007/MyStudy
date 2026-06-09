二分查找的核心三点
第一，中位数的寻找，这点就正常的 mid = begin + (end - begin) / 2即可。
第二，中位数在什么条件下等于end or start，这点往往是根据不同的题目来进行判断。
第三，循环的中止条件，这一点就是**导致会有不同模版的原因**。

而之所以会有不同的中止条件，根源又是下面这行代码。
int mid = start + (end - start) / 2;
这行代码的问题在于 end - start = 1，也就是相差为1的时候， 那么1 / 2 = 0
执行到这里，mid就停止更新，相应的start和end也都停止更新.
而循环的中止条件是通过start和end做比较来判断，此时如果边界值没考虑清楚，就开始死循环了。 

而所谓的不同模版，就是对这个边界值处理的不同导致的
同时，对边界值的处理不同也带来了不同的好处。
但我直接使用了比较通用的模版3，发现大部分问题都能cover，所以对于1和2的好处没啥感受，所以也就不写了。

**模版一** 
循环中止条件为 start <= end，代表差值为1和0的时候都会继续循环。
而我们又知道，end, start差值为1的时候，mid就不更新了。
所以，为了防止mid不更新导致死循环，start，end的更新方式如下。
start = mid + 1;
end = mid - 1;
通过这种方式，保证了mid不更新的时候，循环会中止。

```
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            //差值为1的时候，mid优先等于start
            //差值为0的时候，还会继续循环
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                //差值为1的情况下，mid比target小，加一/
                //差值为0的情况下，mid比target小，加一则结束
                start = mid + 1;
            }
            else {
                //差值为1的情况下，mid比target大，那么减一
                //差值为0的情况下，mid比target大，减一则结束 
                end = mid - 1;
            }
        }      
        return -1;
    }  
```
**模版二**
循环中止条件为 start < end，代表差值为1的会继续循环。
代码相应的处理方法就是 
start = mid + 1;
同时在循环外面加了一个if判断，因为在某些情况下，循环中止但是还没有完全遍。详情参看注释
```
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            //模版一为小于等于，所以需要考虑等于的情况如何中止循环
            //本模版为小于，所以需要考虑考虑差值为1的情况下，如何中止循环，以及差值为1的时候，找到目标值
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                /*
                    举例子，数组[3,4] start = 3 end = 4 start = mid + 1后循环中止
                    也就是说最新更新的start没有判断
                */
                start = mid + 1; 
            }  
            else {
                end = mid;
            }
        }
        cout << start << endl;
        if (nums[start] == target) {
            // 数组[3,4] start = 3 end = 4 mid = 3，此时mid + 1后循环中止，所以需要额外判断一下
            return start;
        }
        return -1;
    }
```
**模版三**
循环中止条件为 start + 1 < end，代表差值为1的时候就中止了
同时
start = mid;
end = mid;
这就代表，如果搜寻到start和end相差为1的时候，循环就已经停止，所以需要在循环结束后继续判断

个人比较喜欢用模版三，因为更加清晰易理解，后面如果需要基于此修改的时候，也更能够想清楚。

```
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) { 
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            //start和end差值为1的时候，直接就中止了。
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[start] == target) {
            //因为差值为1的时候，直接就中止了，所以，需要判断start和end
            return start;
        }
        if (nums[end] == target) {
            //因为差值为1的时候，直接就中止了，所以，需要判断start和end
            return end;
        }
        return -1;
    }
```

最后附上，我的最原始的版本的代码，供大家笑一笑。
```
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 and nums[0] == target) {
            return 0;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while(end > begin) {
            if (end - begin == 1) {
                //防止死循环
                if (nums[begin] == target) {
                    return begin;
                }
                else if (nums[end] == target) {
                    return end;
                }
                else {
                    break;
                }
            }
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                end = mid;
            }
            else {
                begin = mid;
            }
        }
        return -1;
    }
```


