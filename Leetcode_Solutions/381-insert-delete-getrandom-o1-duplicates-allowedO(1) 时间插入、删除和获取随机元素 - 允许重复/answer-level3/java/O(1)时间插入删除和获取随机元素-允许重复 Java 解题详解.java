### 解题思路
   关键词： 时间复杂度为O(1)  存储长度可变  可重复出现  循环遍历查找是否重复出现
    思路：  1.存储长度可变 采用ArrayList集合存储
            2.insert() 添加方法，必添加，因此先添加，长度+1，在循环遍历判断是否存在
            3.remove() 删除方法，先判断 不存在返回false 存在删除 长度-1 返回true
            4.getRandom() 随机返回 获取随机数 范围为0-length 直接返回list.get(random)即可

### 代码

```java
class RandomizedCollection {
    /**
     * 长度可变 O(1) 所以要采取集合
     */
    //private int[] ints;
    private List<Integer> integerList;
    private int length;

    /**
     * Initialize your data structure here.
     */
    public RandomizedCollection() {
        integerList = new ArrayList<Integer>();
        length = 0;
    }

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
     */
    public boolean insert(int val) {
        integerList.add(val);
        length++;
        for (int i = 0; i < length - 1; i++) {
            if (integerList.get(i) == val) {
                return false;
            }
        }
        return true;
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified element.
     */
    public boolean remove(int val) {
        for (int i = 0; i < length; i++) {
            if (integerList.get(i) == val) {
                integerList.remove(i);
                length--;
                return true;
            }
        }
        return false;
    }

    /**
     * Get a random element from the collection.
     */
    public int getRandom() {
        //去掉集合为空时 获取问题
        if (length == 0) {
            return 0;
        }
        Random random = new Random();
        int i = random.nextInt(length);
        return integerList.get(i);
    }
}
```