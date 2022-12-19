#### 推理
![在这里插入图片描述](https://pic.leetcode-cn.com/53c09400dd0807aec9c99124d417932b85c0a6b251268c2358b25eeef3fc007f-file_1581708917922)
如果是按照正常顺序构造二叉树，理应是
```
                   1
        2                    3
   4         5          6          7 
8     9   10    11   12    13   14    15 
....
```
因为题目给出的是个完全二叉树，下一层的节点是当前层的2倍。

假设 $label = 14$，顺序构造的上一层 $label / 2 = 7$
但是按照原图来看理应是```4```才符合结果 。
假设 $label = 11$，顺序构造的上一层 $label / 2 = 5$
但是按照原图来看理应是```6```才符合结果。
此时可以看到按照```之```行排列的计算结果是```顺序```排列的 **对称点**
>(7 >< 4)、(6 >< 5)
>
1. **label = 14:** 
$$4+7=14/2+X$$
```4+7```是第三层的左右之和，此时 ```label/2 = 7```,另一个位置的值是```4```的时候是其对称点。


2. **label = 11:** 
$$4+7=11/2+X$$
```4+7```是第三层的左右之和，此时 ```label/2 = 5```,另一个位置的值是```6```的时候是其对称点。


那么现在只要知道了当前在什麼位置```N```，就能根据完全二叉树的性质求出当前左右之和
$$Left+Right = 2^{N-1}+(2^N-1)$$
$$Left+Right = 2^{N-1}+2^N-1=2^{N-1}+2*2^{N-1}-1=3*2^{N-1}-1$$
$$X=(Left+Right)-Label/2 = 3*2^{N-1}-1 -Label/2$$
那么现在只要知道当前的位置```N```，以及当前的值```label```就行求出下一个位置的值```X```。将```X```作为下一个位置的```label```继续求解直到完毕。

$$
label(N) = \{_{1,N = 1}^{3*2^{N-1}-1,N>1}
$$
#### 求解
当传入的label已知，同时也能求出```N```
```java		
var N = (int) (Math.log(label) / Math.log(2));// 2^N=label,N=log2^label
```
到此所有的未知数都已经确认完毕。
```java
public List<Integer> pathInZigZagTree(int label) {
	ArrayList<Integer> integers = new ArrayList<>();//0.初始化存放结果的变量
	var a = (int) (Math.log(label) / Math.log(2));//2.计算label所在的层
	while (label > 1) {//5.循环直到遇到特殊情况1
		integers.add(label);//3.将label的结果添加到数组中
		label = (int) (3 * Math.pow(2, --a) - label / 2 - 1);//4.计算下一个label的值
	}
	integers.add(1);//6.添加特殊情况 1
	Collections.reverse(integers); //7.翻转数组
	return integers;//1.返回结果
}
```
---

##### [1.博客地址](https://blog.csdn.net/weixin_42322309)
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。