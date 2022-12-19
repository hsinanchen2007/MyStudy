### 解题思路
使用Map来存储每个节点的key(key = level*10 + position)，可以快速定位到父节点，每个子节点把父节点的值加入到自己的值中（即权值累加），继续往孩子递推，最后找到map中所有的叶子节点值相加即可。

不过这个思路遍历了两次，效率可以继续优化，从后往前遍历，把全部的路径和（权值）累加到根节点，这样就只需要遍历一次，但是需要注意的是，如果一个节点**每**多出现**1**个孩子，那么这个节点**所有的父节点**的值就要**全部**累加**1**次，换句话说，就是一个节点如果有**2个孩子**，其本身的值就要加**2**次，其*兄弟节点*如果**只有1个孩子**，那么当前节点的**父节点**的值就要加**3**次（**自己2个孩子，兄弟1个孩子，所以父亲节点要加3次**），如果*兄弟节点*是**2**个孩子，那么当前节点的**父节点**的值就要加**4**次（具体逻辑和之前的一样）。

### 代码

```java
class Solution {
    public int pathSum(int[] nums) {
        // key : level * 10 + position -> value : 包含路径上所有元素的和
        Map<Integer,Integer> indexValueMap = new HashMap<>();
        indexValueMap.put(getNumKey(nums[0]),getNumValue(nums[0]));
        for (int i = 1;i< nums.length;i++){
            int num = nums[i];
            int level = getNumLevel(num);// 获取层
            int position = getNumPosition(num);// 获取位置
            int value = getNumValue(num);// 获取值
            int parentKey = (level - 1) * 10 + ((position + 1) >> 1);// 父节点的key
            int parentValue = indexValueMap.get(parentKey);// 父节点的值
            // 孩子节点的值加入
            indexValueMap.put(getNumKey(num), parentValue + value);
        }

        int sumValue = 0;
        for (Map.Entry<Integer,Integer> entry : indexValueMap.entrySet()){
            Integer key = entry.getKey();
            int childLevel = (key / 10 + 1) * 10;// 孩子的层
            int childPosition = (key % 10) << 1;// 孩子的位置
            int childKey = childLevel + childPosition;// 孩子的key
            // 左右孩子都不存在，就是表示是叶子节点
            if (!indexValueMap.containsKey(childKey - 1) && !indexValueMap.containsKey(childKey)){
                // 叶子节点值加入
                sumValue += entry.getValue();
            }
        }
        return sumValue;
    }

    /**
     * 获取数字的key
     * @param num num
     * @return key
     */
    private int getNumKey(int num){
        return num / 10;
    }

    /**
     * 获取数字的层
     * @param num num
     * @return level
     */
    private int getNumLevel(int num){
        return num / 100;
    }

    /**
     * 获取数字的位置
     * @param num num
     * @return position
     */
    private int getNumPosition(int num){
        return num / 10 % 10;
    }

    /**
     * 获取数字的值
     * @param num num
     * @return value
     */
    private int getNumValue(int num){
        return num % 10;
    }
}
```