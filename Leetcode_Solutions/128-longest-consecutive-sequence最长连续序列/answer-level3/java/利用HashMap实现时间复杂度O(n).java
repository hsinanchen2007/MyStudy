
# **方法1：**
    这道题普通想法就是排序(**时间复杂度O(nlog(n))**)，然后再循环取值判断是否连续，并用max函数来取得每次子段的长度。

![一般方法.png](https://pic.leetcode-cn.com/b8eb74c0b043c393278ff97cd627693edde8bdc43171d482c19c6247b1b4c322-%E4%B8%80%E8%88%AC%E6%96%B9%E6%B3%95.png)
    代码：略


![分割线.png](https://pic.leetcode-cn.com/f0a97fd94f542faabcfd02b36d2b38b817d8e6809696a67fcbb21a29e0014acf-%E5%88%86%E5%89%B2%E7%BA%BF.png)


# **方法2：HashMap**
    由HashMap特点，在理想情况下，取值操作都是O(1)的，所以使用HashMap。**比起上一种方式，可以不需要排序，直接找到当前元素的上一个元素和下一个元素**

流程：
    1. 先把数组存到Map<Integer, Boolean>中，其中键值对含义为：<值，是否访问过>
    2. 声明一个变量，存子段长度最大值
    3. 写一个方法findCurrentStandLength(Map<Integer, Boolean> numsMap, int currentKey)；方法作用：使用递归，来判断该元素(currentKey)所在子段的长度。例如题中数组：当currentKey=4时，利用递归来遍历，分别访问map中的[4,3,2,1]，最后返回长度为4，并且把[3,2,1]的value都设置为true(访问过)。
    4. for循环遍历数组
        (1)访问过当前元素：跳过
        (2)没有访问过：使用findCurrentStandLength方法来求子段长度
    5. maxLength更新最大值
    

代码：
```
public static int longestConsecutive(int[] nums) {

        if (nums == null || nums.length == 0) {
            return 0;
        }

        //通过hash散列方式存数据，为了查找速度为1
        Map<Integer, Boolean> numsMap = new HashMap<>();

        //先把nums数组的值存到map中
        for (int num : nums) {
            numsMap.put(num, false);//存入（值，是否被访问过）
        }

        int maxLength = 0;//最大连续子段的长度

        for (int i = 0; i < nums.length; i++) {

            //如果没有被访问过
            if (!numsMap.get(nums[i])){
                maxLength = Math.max(maxLength, findCurrentStandLength(numsMap, nums[i]));
            }
        }

        return maxLength;
    }

    public static int findCurrentStandLength(Map<Integer, Boolean> numsMap, int currentKey) {

        //如果键存在于nums数组中，且当前键没有被访问过，则访问
        if (numsMap.containsKey(currentKey) && !numsMap.get(currentKey)) {

            numsMap.put(currentKey, true);//标志为访问过

            return 1
                    + findCurrentStandLength(numsMap, currentKey - 1) //递归访问当前值连续的前一个数
                    + findCurrentStandLength(numsMap, currentKey + 1);//递归访问当前值连续的后一个数
        }else {
            return 0;
        }

    }
```
