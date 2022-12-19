### 前提

- 从$index=0$开始数，每次数$m$个数，将坐标对应$m-1$的数字删除，但这个$m-1$可能超过`list`最大坐标$index=(n-1)$。

  - 例如：$n=5,m=6$ 

    
![002_m52_1.png](https://pic.leetcode-cn.com/29228f233b83a7fdaa61385d61574c882ab4a5a6632a8191165e30bddec3fff5-002_m52_1.png)

- 所以 $m$ 满 $n$ 个, `index`就归零接着数，所以要对 $m$ 取余。有`n`个数的时候，我们删除数字的`index`为
  $$
  removeindex = (m- 1) \mod n
  $$

  - 例如：当m=5，n=5时：
    $$
    m \mod n = 5 \mod 5 = 0
    $$
    而此时第五个对应的index为4

  - 所以应该$(m-1)\mod n$ ，而不能是$(m \mod n) -1$因为
    $$
    (m \mod n) -1 =（5 \mod 5）-1 = -1
    $$
    

### 算法



-   设有5个数，`m=3`，设此时数字所在的列表为**list1**, `list1 = [0,1,2,3,4]`

     ```python
     数字：
     0 1 2 3 4
     index：
     0 1 2 3 4
     ```

1. 第一遍删除从index=0开始，数3个数字，删除的数字值为2，**坐标**在`list1`中为，
  
![image.png](https://pic.leetcode-cn.com/ad2c95dc70567186c64867094c419f73b94d5c1a4e0ee1c42610f8d5a52a4e3f-image.png)

   
![002_m52_3.png](https://pic.leetcode-cn.com/3a894969c7cd2fbdc8832119cb18f35de8987b70ebd6ce110a9b9c59c48d1da8-002_m52_3.png)

   

2. 删除一个数后, 此时列表中有$n-1$个数，设数字所在的列表为**list2**，`list2=[3,4,0,1]`, 并且**坐标0**重新定位。第二遍删除从**新的**$index=0$开始，数3个数字，删除的数字值为0，**坐标**在`list2`中为
   
![image.png](https://pic.leetcode-cn.com/9ad1032094beb91f38a34d3aa245efc37c2ae739ea05e045f3d5957e7678eb30-image.png)
   
![002_m52_4.png](https://pic.leetcode-cn.com/7dac37efbf25d3f0e0075f0b0c03ef09715bb4116c50cce5c40333b0409479bb-002_m52_4.png)

   

3. **此处注意**，可找出**list2**对应在**list1**中的规律

   - 在**list1**中删除一个数字后，**list2**的index=0从删除数字的下一个数字开始，这个数字在**list1**中对应为

  
![image.png](https://pic.leetcode-cn.com/d33e905afe862354c923b51684e61dd809d3df985408fa05b077d0011e9f422c-image.png)
   - 而在第二遍删除时，将**list2**中的第**m**个数字删除，相当于删除**list1**中的第$reindex+m$个数字即`index`为$reindex+m-1$的数字：此处意为从`reindex`开始，往后数m个数，即从数字3开始数第三个数字为0，对应在**list1**中的坐标为0
   
![image.png](https://pic.leetcode-cn.com/2730c0ca72f6c07e1ff4ffd01d25a66fc601b4cf27554d54af28b3d1c9d4a034-image.png)

    

   

4. 回到本题中，求的是最后剩下的一个数字

   - 设最后一个数字$x$在**list1**中的坐标为`list1_x`, 在**list2**中的坐标为`list2_x`，注意此处的`list2_x`为数字$x$在`list2_x`中的坐标，并不是第三步中的第几个数，`list2_x`对应的是list2中的第`list2_x+1`个数

   - 由第三步中得到的规律可知, ：
    
![image.png](https://pic.leetcode-cn.com/104867dcdedbf4922f14f3033aa54d275293e4dca93b7845558069cf775ae57a-image.png)



5. 由于在`list1`中index与此坐标对应的数字一致, 所以求解出留下的最后一个数字对应在`list1`中的`index`即可：

   ```python
   def recursive(n, m):
       # 只剩一个数字时，此时的index为0
       if n == 1:
           return 0
       x = recursive(n - 1, m)
       return ((m + x) % n)
   ```

   在递归时，如果list中只剩下一个数字那么这个数字在最后一个list中index为0

​    

