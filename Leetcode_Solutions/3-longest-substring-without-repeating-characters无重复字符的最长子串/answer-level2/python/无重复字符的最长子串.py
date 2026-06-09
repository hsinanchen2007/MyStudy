__思路__：
1.将字符串逐个导入字典（哈希表），循环（次数index）按照导入顺序标记每个字母的序号（字典值），字典的键为字母，类似于dict[A]=0，dict[B]=1···；
2.遇到重复字母，计算两个相同字母间的距离（所夹字母个数），并用flag.append(index-duplicate)记录；
2.1.对于‘abcabcabb’这种，用第二次导入a的所需循环次数4减去duplicate(=dict[a])，计入flag，更新dict[a]=4;
2.2.对于‘wobgrovw’这种，
2.2.1.'o'的情况类似2.1，w的情况如下处理：
2.2.2.记duplicate=dict[o](=1，2.2.1中先给duplicate赋值，再更新dict[o]，因此，duplicate=1)，跟进一次循环以后，出现w重复，判断w的位置是否在o前面，如果是用duplicate进行“去重复字母运算”；如果w在o后面，赋值  duplicate=dict[w]（即更新duplicate），再进行“去重复字母运算”
2.3.然后将2.1或2.1计算距离存入flag；
3.遍历字符串，取flag中最大值返回；


__代码__：

![image.png](https://pic.leetcode-cn.com/410187198e4eaaf772f5b1ed7b1d309595da5ef27813403a0a0c5dabfba0887d-image.png)

__结果：__

![image.png](https://pic.leetcode-cn.com/504352892821c24ac83c304413c2d67142a95402f486c61d12fb7d51dad64c00-image.png)