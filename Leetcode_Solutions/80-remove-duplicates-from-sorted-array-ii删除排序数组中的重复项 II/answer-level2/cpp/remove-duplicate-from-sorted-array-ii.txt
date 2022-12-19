和26解法类似

解法一
重复元素多余2个的使用覆盖的方法
```
vector<int> remElement(vector<int>& arr,int index) {
        for (int i = index + 1; i < arr.size(); ++i) {
            arr[i - 1] = arr[i];
        }
        return arr;
    }
    int removeDuplicates(vector<int>& nums) {
        int i = 1, count = 1, length = nums.size();
        while (i < length) {
            if (nums[i] == nums[i - 1]) {
                count ++;
                if (count > 2) {
                    remElement(nums, i);
                    i--;
                    length--;
                }
            } else {
                count = 1;
            }
            i++;
        }
        return length;
    }
```


解法二

```
int removeDuplicates(vector<int>& nums) {
        //有序、原地修改
        if (nums.size() == 0)
            return 0;
        const int MAX_COUNT = 2;
        int k = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[k] == nums[i]) {
                count ++;
                if (count <= MAX_COUNT)
                    nums[++k] = nums[i];
            }else {
                count = 1;
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
```
