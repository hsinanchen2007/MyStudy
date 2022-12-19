暴力破解法的缺点导致我们选择了双指针法：
代码：
```
def alg(ls):
    list_enum=[]
    area_last=0
    for x,y in enumerate (ls):
        list_enum.append([x,y])
    length=len(list_enum)
    for i in range(length):
        for j in range(i+1,length):
            print(j)
            area=(min(list_enum[i][1],list_enum[j][1])*(list_enum[i][0]-list_enum[j][0]))
            #print("area=",area)
            if area>=area_last:
                area_last=area
                #target=[i,j]
    #print("area=",area_last,"target=",target)
    #print("list_enum=",list_enum[1],len(list_enum))
    return area_last
```
如下图：
![图解.jpg](https://pic.leetcode-cn.com/49c8ac88226a1523bdacee54689e101ee712b61ef3c4d270d3c11b3c1a9d3117-%E5%9B%BE%E8%A7%A3.jpg)
我一开始一直想不通的是：即使8和3中3是最小的，但是8和3的index差值是最大的，所以取决的因素有两个：1.两个水柱中最小的那个 2.两个水柱的index差 

我一想到这我就觉得只能暴力求解了，后来有想到了两个指针一个向前一个向后，保证在比较的同时能保证不管是移动Left 还是移动right， 这个index的差还是一致的，这句话要好好理解，所以我们在index差一致的情况时候，取水柱高的那个指针（left或者是right）不动，然后指针向（right或者是left）移动，这就明朗了。
也就是我们对暴力求解的两个求解中的两个子问题转化为一个：
在每次比较的index差恒定的情况下去计算水柱面积。
下面的就是双指针的解法：
```
def alg(ls):
    area_last=0
    left=0
    right=len(ls)-1
    while(left!=right):
        area=min(ls[left],ls[right])*(right-left)
        if area>=area_last:
            area_last=area
        if ls[left]>ls[right]:
            right-=1
        else:
            left+=1
    return area_last
```
思路就是这个思路，这个思路的转化很重要，他能帮我们解决不仅仅是这题的面积，index差与y值有联系的问题都可以往双指针这想。
让我们再看一下这个双指针的方法：
对照上图，先计算left和right之间的水柱面积，之后开始： 8和3哪个大？肯定是8，那么8不动，right往左边移，8心想：我都比你大了，你还是走吧，因为"下一个数跟我相乘的面积"肯定比"下一个和你相乘的面积"大的概率很大哦，3心想：你说的确实是的，下一个数跟我的距离和下一个数跟你的距离index是一样的，我3没你8大，但是在这之前我们计算下我们之间的面积好吗？防止下一次你碰到的数很小，而我碰到的数很大呢，以至于碰不到最优解呢，因为这样的话我们就不能像暴力破解法那样去枚举所有的可能了。 8说：好吧，你想的很对，我们计算下当前的面积，但是你放心，这样走肯定是有最优解的。
ps:这个最优解是否被跳过的证明可以看[其他人](https://leetcode-cn.com/problems/container-with-most-water/solution/zhi-guan-de-shuang-zhi-zhen-fa-jie-shi-by-na-kong/)的

