####  方法一：删除多余的重复项
由于输入数组已经排序，所以重复项都显示在旁边。题目要求我们不使用额外的空间，在原地修改数组，而最简单的方法就是删除多余的重复项。对于数组中的每个数字，若出现 `2` 个以上的重复项，就将多余的重复项从数组列表中删除。

**算法：**

1. 我们需要在遍历数组元素的同时删除多余的重复项，那么我们需要在删除多余重复项的同时更新数组的索引，否则将访问到无效的元素或跳过需要访问的元素。
2. 我们使用两个变量，`i` 是遍历数组的指针，`count` 是记录当前数字出现的次数。`count` 的最小计数始终为 `1`。
3. 我们从索引 `1` 开始一次处理一个数组元素。
4. 若当前元素与前一个元素相同，即 `nums[i]==nums[i-1]`，则增加计数 `count++`。若 `count > 2`，则说明遇到了多余的重复元素 ，要从数组中删除它。由于我们知道这个元素的索引，可以使用 `del`，`pop` 或 `remove` 操作（或你选择语言支持的任何相应的操作）从数组中删除它。由于删除了一个元素，所以我们的索引应该要减一。
5. 若当前元素与前一个元素不相同，即 `nums[i] != nums[i - 1]`，说明我们遇到了一个新元素，则更新 `count = 1`。
6. 由于我们从原始数组中删除了所有多余的重复项，所以最终在原数组只保留了有效元素，返回数组长度。

```python [solution1-Python]
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Initialize the counter and the array index.
        i, count = 1, 1
        
        # Start from the second element of the array and process
        # elements one by one.
        while i < len(nums):
            
            # If the current element is a duplicate, 
            # increment the count.
            if nums[i] == nums[i - 1]:
                count += 1
                
                # If the count is more than 2, this is an
                # unwanted duplicate element and hence we 
                # remove it from the array.
                if count > 2:
                    nums.pop(i)
                    
                    # Note that we have to decrement the
                    # array index value to keep it consistent
                    # with the size of the array.
                    i-= 1
                
            else:
                
                # Reset the count since we encountered a different element
                # than the previous one
                count = 1
           
            # Move on to the next element in the array
            i += 1    
                
        return len(nums)
```

```java [solution1-Java]
class Solution {
    
    public int[] remElement(int[] arr, int index) {
        
        //
        // Overwrite the element at the given index by 
        // moving all the elements to the right of the
        // index, one position to the left.
        //
        for (int i = index + 1; i < arr.length; i++) {
            arr[i - 1] = arr[i];
        }
        
        return arr;
    }    
    
    public int removeDuplicates(int[] nums) {
        
        // Initialize the counter and the array index.
        int i = 1, count = 1, length = nums.length;
        
        //
        // Start from the second element of the array and process
        // elements one by one.
        //
        while (i < length) {
            
            //
            // If the current element is a duplicate, 
            // increment the count.
            //
            if (nums[i] == nums[i - 1]) {
                
                count++;
                
                //    
                // If the count is more than 2, this is an unwanted duplicate element
                // and hence we remove it from the array.
                //    
                if (count > 2) {
                    
                    this.remElement(nums, i);
                    
                    //
                    // Note that we have to decrement the array index value to
                    // keep it consistent with the size of the array.
                    //    
                    i--;
                    
                    //
                    // Since we have a fixed size array and we can't actually
                    // remove an element, we reduce the length of the array as
                    // well.
                    //
                    length--;
                }
            } else {
                
                //
                // Reset the count since we encountered a different element
                // than the previous one.
                //
                count = 1;
            }
                
            // Move on to the next element in the array
            i++;
        }
            
        return length;
    }
}
```

**复杂度分析**

* 时间复杂度：让我们看看最耗时的操作是什么：
	- 我们必须遍历数组中的所有元素，若数组中有 `N` 个元素，则花费的时间为 $O(N)$。
	- 删除多余的重复项，`del` 操作也是 $O(N)$。
	- 最糟糕的情况是数组中的元素都相同，则我们需要执行 $N-1$ 次的删除操作，则需要花费 $O(N^2)$。
	- 总的复杂度：$O(N) + O(N^2) \equiv O(N^2)$
* 空间复杂度：$O(1)$，我们在原地修改数组。


####  方法二：覆盖多余的重复项
**算法：**

1. 我们使用了两个指针，`i` 是遍历指针，指向当前遍历的元素；`j` 指向下一个要覆盖元素的位置。
2. 同样，我们用 `count` 记录当前数字出现的次数。`count` 的最小计数始终为 `1`。
3. 我们从索引 `1` 开始一次处理一个数组元素。
4. 若当前元素与前一个元素相同，即 `nums[i]==nums[i-1]`，则 `count++`。若 `count > 2`，则说明遇到了多余的重复项。在这种情况下，我们只向前移动 `i`，而 `j` 不动。
5. 若 `count <=2`，则我们将 `i` 所指向的元素移动到 `j` 位置，并同时增加 `i` 和 `j`。
6. 若当前元素与前一个元素不相同，即 `nums[i] != nums[i - 1]`，说明遇到了新元素，则我们更新 `count = 1`，并且将该元素移动到 `j` 位置，并同时增加 `i` 和 `j`。
7. 当数组遍历完成，则返回 `j`。


```python [solution2-Python]
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Initialize the counter and the second pointer.
        j, count = 1, 1
        
        # Start from the second element of the array and process
        # elements one by one.
        for i in range(1, len(nums)):
            
            # If the current element is a duplicate, 
            # increment the count.
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                # Reset the count since we encountered a different element
                # than the previous one
                count = 1
            
            # For a count <= 2, we copy the element over thus
            # overwriting the element at index "j" in the array
            if count <= 2:
                nums[j] = nums[i]
                j += 1
                
        return j
```

```java [solution2-Java]
class Solution {
    
    public int removeDuplicates(int[] nums) {
        
        //
        // Initialize the counter and the second pointer.
        //
        int j = 1, count = 1;
        
        //
        // Start from the second element of the array and process
        // elements one by one.
        //
        for (int i = 1; i < nums.length; i++) {
            
            //
            // If the current element is a duplicate, increment the count.
            //
            if (nums[i] == nums[i - 1]) {
                
                count++;
                
            } else {
                
                //
                // Reset the count since we encountered a different element
                // than the previous one.
                //
                count = 1;
            }
            
            //
            // For a count <= 2, we copy the element over thus
            // overwriting the element at index "j" in the array
            //
            if (count <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，我们遍历每个数组元素一次。
* 空间复杂度：$O(1)$。