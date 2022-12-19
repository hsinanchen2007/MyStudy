本题可以采取和上题类似的策略：对每个重复的元素则赋值给后面不同的元素。但是注意这里需要保证不会重复赋值，因此比较可行的方法是进行节点的交换


```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		if (size == 0)
			return 0;

		int ptr = 0;
		int end = 0;
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == val)
			{
				if (end < i)
					end = i;
				if (end == size)
					return ptr;

				while (nums[end] == val)
				{
					end++;
					if (end == size)
					{
						return ptr;
					}
				}
				int tmp = nums[ptr];
				nums[ptr] = nums[end];
				nums[end] = tmp;
				end++;
				ptr++;
			}
			else
			{
				ptr++;
			}
		}
		return ptr;
	}
};

```


但是上述做法的代码看起来颇为繁琐，其实可以更进一步的简化思想：我们只要每次把不同于val的值赋值在前列就可以完成了


```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) 
            return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) 
        {
            if (nums[j] != val) 
            {
                nums[i] = nums[j];                
                i++;
            }
        }
        return i;
	}
};
```




还有没有办法优化性能呢？是有的。上述方法存在一个普遍问题：对于检索过的val的值最后还会检查一遍。但是其实是不需要检查的：我们可以将重复的值替换为末尾的值， 并且不再检查它


```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
	}
};
```
