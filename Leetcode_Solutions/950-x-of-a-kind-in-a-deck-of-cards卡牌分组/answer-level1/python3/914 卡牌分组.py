### 解题思路
作为一个小白，真的好多基础的东西都不懂，便查边做，但是最后还是写了出来。记录一下解体思路与遇到的问题吧

解题思路，这个问题一开始理解错了，没有想到同样的数可以分成好几组，anyway，写一下最后的解体思路。
    第一步：对deck进行排序，因为打算从list的pop从最后一个往外抽数，进行分组，所以如果不按顺序排列无法进行分组，这里有个小插曲，如果用new_deck = deck.sort()进行排序的话后边用pop会报错，所以只能用list.sort(deck).
    第二步：就是生成一个motherlist，里边的item都是list，是将deck中的数挪入其中，因为一开始已经排好序了所以非常简单，如果现在pop出来的数和之前的数一样，就加入一个组，不一样，就新建一个组。如果有组的个数少于二直接return False就好了
    第三步：新建一个index的list，目的是为了找到X，是将motherlist中所有子list的length收集起来。
    第四步：找最大公约数， 我的办法是先找到最小的那个数的所有能整除的数，变成一个list，其中元素最大不会过过自身，最小值设定为比二大。然后用所有在index中数进行删选，如果gcd_list 中存在不能被 index中的数整除的数，从gcd_list 中删除，这里又有一个小插曲，不能用remove，因为在for循环中用remove他会默认跳删，
https://blog.csdn.net/circle2015/article/details/64444300
    详情在链接里
    所以我用了条件选择[each for each in gcd_list if div % gcd == 0]

时间复杂度: sort 的复杂度是O(nlogn),总体应该是O(n^2)

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        list.sort(deck)
        if len(deck) == 0:
            return 'false'
        motherlist = list()
        last_num = None
        while len(deck) != 0:
            num = deck.pop() 
            if  num != last_num:
                motherlist.append([num])
                last_num = num
            else:
                motherlist[len(motherlist)-1].append(num)
        index = [len(motherlist[i]) for i in range(len(motherlist))]
        div = min(index)
        if div < 2:
            return False
        gcd_list = []
        for gcd in range(2,div+1):
            if div % gcd == 0:
                gcd_list.append(gcd)
        for i in index:
            gcd_list = [each for each in gcd_list if i % each == 0]
            '''
            for gcd in gcd_list:
                if i % gcd != 0:
                  gcd_list.remove(gcd) remove不可行，会跳删
            '''
        if len(gcd_list) == 0:
            return False
        return True
            
            

```