### 1、解题思路：
        1.1 主要采用set的特性，set中的元素不能重复。先遍历一遍nums数组，将其中元素都放到set集合中。
        1.2 比较nums数组的长度和set集合的长度，看是否相等，若相等，则意味着nums数组中不存在重复元素，若不等，则表明nums数组中存在重复元素。
### 2、代码如下：
```
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        for (Integer i: nums){
            set.add(i);
        }
        if (nums.length > set.size()){
            return true;
        }else {
            return false;
        }
    }
```
### 3、运行效果，由于官方解法中的哈希表。
    耗时 beat 接近80%