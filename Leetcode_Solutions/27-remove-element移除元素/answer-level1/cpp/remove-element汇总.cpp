要求：
     1.元素顺序可以改变
     2.不要使用额外的空间
     3.删除之后保持原有顺序
  
**解法一**
  
```
int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
```

**解法二**
优化解法一

```
int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                if (k != i)
                    nums[k++] = nums[i];
                else
                    k++;
        }
        return k;
    }
```

**解法三**
使用解法二会遍历2n次，因为可以不保证原有的顺序，我可以定义两端指针遍历一次即可

```
int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
        while (k < n) {
            if (nums[k] == val) {
                nums[k] = nums[n - 1];
                n--;
            }else {
                k++;
            }
        }
        return n;
    }
```

