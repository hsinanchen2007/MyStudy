```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //10000000000
        int val = 2048;
        //01111111111
        int aval = val - 1;
        int[] slot = new int[val];
        for (int i = 0; i < nums.length; i++) {
            int oldv = slot[(target - nums[i]) & aval];
            if (0 != oldv) {
                return new int[]{oldv - 1, i};
            }
            slot[nums[i] & aval] = i + 1;
        }
        return null;

    }
}
```
*这段代码是提交记录中0ms的代码，不是出自本人，花了一段时间理解这段代码，记录一下思考过程用于彻底理清思路，如果发现说的有什么问题请不吝赐教。*
1.初始化一个数组，每一个数组元素的默认值为0
2.设定2047为按位与的原因：2047的二进制数11111111111，小于2048的所有数字与之进行按位与运算，得到的结果都为其本身，如数字7，与2047进行按位与运算
```
11111111111
00000000111
```
最后的结果为00000000111，即7本身
3.怎么判断？
假设有测试用例nums=[2,3,7,9],target=9
![image.png](https://pic.leetcode-cn.com/431e6b560243c1578824934f4616014a46b6c0b5111ace947bb76715d425b785-image.png)
刚进入的时候（i=0），oldv = slot[(target - nums[i]) & aval] ==> oldv = slot[(9 - 2) & 2047] = slot[7]=0
if语句不执行，进入
```
slot[nums[i] & aval] = i + 1;
```
这句代码，将slot数组中索引为nums[i]（2）的默认值0更改为i+1（1）//**slot[2]=1**
![image.png](https://pic.leetcode-cn.com/637c4cde575f18b638b6e1de96d65d9d759f49c6315813f086baa12599d6a8f1-image.png)
下一重循环（i=1）oldv = slot[(target - nums[i]) & aval] ==> oldv = slot[(9-3) & 2047] = slot[6]=0
if语句依然不执行，进入
```
slot[nums[i] & aval] = i + 1;
```
将slot数组中索引值为3的数值设为2//**slot[3]=2**
![image.png](https://pic.leetcode-cn.com/da94eeb2686c7140bd849b7684b1646e4fa8a1812f4180ae50c706570f8c1177-image.png)
下一重循环（i=2）oldv = slot[(target - nums[i]) & aval] ==> oldv = slot[(9-7) & 2047] = **slot[2]**
![image.png](https://pic.leetcode-cn.com/5776dab00aecd80d28ba056ce45ee1be7ed2ba9f74624ceb92402a07fa41e77a-image.png)

到这里**oldv = slot[2] = 1**,进入if语句执行return语句，循环结束，结果为[0,2]

*原理基于数组的拷贝，并非原样拷贝，而是将原数组的key value值调换，value值作为key，key+1（区别于默认值0）作为value值。
每一次循环的索引只有原数组的值a和target-a这两索引，每次进行判断slot数组中target-a这个索引对应的值是否为0，当不为0时，说明前方已经遍历过一个值为target-a的数字，与当下的a数字相加可以得到两数之和target，而slot[target-a]对应的值就是数字target-a的索引+1。*


虽然这个代码效率在这个执行环境中是最快的，但个人觉得没有比官方的最快解法好，因为本算法限制了原数组的长度不能超过2048的同时，在原数组长度极短（4）的情况下，在空间上造成了浪费（2044）。








