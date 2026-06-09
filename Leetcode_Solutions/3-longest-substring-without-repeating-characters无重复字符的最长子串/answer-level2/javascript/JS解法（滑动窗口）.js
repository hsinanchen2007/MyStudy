用一个数组存储并不断更新子串，用一个变量l存储这个过程中最长的子串长度。
具体代码及注释如下：

```
 if(s==""){
        return 0;
    }
    let arr = s.split('');
    let temp = [arr[0]];
    //无重复子串起始点
    let head = 0;
    //无重复子串结尾点
    let tail = 1;
    //最大长度
    let l = 1;
    while(tail<arr.length){
        if(temp.indexOf(arr[tail])==-1){
            //不重复，则加入当前字符
            temp.push(arr[tail]);
            //更新最大长度
            l = temp.length>l?temp.length:l;
            tail++;
        }else {
            //出现重复字符
            //将起始点更新为重复的那个字符所在位置后一位（有点拗口，但是是这道题的精髓）
            head = temp.indexOf(arr[tail])+head+1
            //更新尾指针位置（更好的方式是tail++,然后删除子串temp的前head位）
            tail = head+1;
            //重置无重复子串
            temp = [arr[head]];
        }
    }
    return l;

```
