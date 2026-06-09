### 解题思路
1. 使用C语言，因为没有set容器，自己写set容器中的contain与remove方法太繁琐， 而且如果采用遍历方法写set，会增加时间复杂度，因此这里只能使用哈希表来实现滑动窗口法。时间复杂度为（O(N^2)）；
2. 这里有个坑就是strlen(s)不能求两次会超时，而用C++不会超时；因此写成n = strlen(s)，方便两次使用。
这个算法时间执行时间还是偏高，比相同代码下的C++慢的太多，不知道什么原因；
3. 看了官方解答后，发现可以对滑动窗口法进行优化，将哈希表改成记录数组的下标，这里不赘述。

### 代码

```c


int lengthOfLongestSubstring(char * s){
    int visited[256] = { 0 };
    int n = strlen(s);
    int len = 0 , max = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n ; j++){
            if(visited[s[j]] == 0){
                visited[s[j]] = 1;
                len++;
            } else break;
        }
        max = max > len ? max : len;
        memset(visited , 0, sizeof(visited));
        len = 0;
    }
    return max;
}


```