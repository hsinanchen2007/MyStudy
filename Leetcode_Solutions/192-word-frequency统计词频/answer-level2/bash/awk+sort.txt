本题先用`cat`命令和管道命令`|`将文件内容传给`awk`。

在`awk`中我们用一个*字典(?)*`count`储存每个单词的词频，先遍历每一行(`awk`自身机制)的每一个字段(i<=NF)，然后用该字段本身作为`key`,将其`value++`；最后用一个`for`循环输出`count`数组中的每个元素的`key`(词)及其`value`(词频)。

最后用`|`管道命令传给`sort`命令：

- `-r`是倒序排序，相当于`DESC`
- -n是将字符串当作`numeric`数值排序
- `-k`则指定用于排序的字段位置，后跟`2`指将第二位的`count[k]`(词频)作为排序的`key`

```sh
cat words.txt | 
awk '{ 
    for(i=1;i<=NF;i++){
        count[$i]++
    } 
} END { 
    for(k in count){
        print k" "count[k]
    } 
}' | 
sort -rnk 2
```

最后打个小广告 -> [我的博客](https://www.cocobolo.top/linux/2019/07/04/192.%E8%AF%8D%E9%A2%91%E7%BB%9F%E8%AE%A1(awk).html)有更详细的本题知识点。
