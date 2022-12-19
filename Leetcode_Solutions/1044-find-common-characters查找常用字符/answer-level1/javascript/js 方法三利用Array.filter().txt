方法一：用数组存每个字符串各字符出现的次数，把数组放在list中，最后比较list中数组代表各字符出现次数的最小值
```
var commonChars = function(A) {
    let arrayList = [];
    for (let str of A) {
        let arr = new Array(26).fill(0);
        for (let i = 0; i < str.length; i++) {
            arr[str[i].charCodeAt() - 'a'.charCodeAt()]++;
        }
        arrayList.push(arr);
    }
    let res = [];
    for(let i = 0; i < 26; i++){
        let min = 100;
        for (let j = 0; j < arrayList.length; j++) {
            if (arrayList[j][i] < min) {
                min = arrayList[j][i];
            }
        }
        for(let k = 0; k < min; k++){
            res.push(String.fromCharCode(i + 'a'.charCodeAt()));
        }
    }
    return res;
};
```
方法二：跟方法一的区别就是遍历每个字符串的时候，直接比较代表出现字符数的数组各项的大小
```
var commonChars = function(A){
    let arr = new Array(26).fill(100);
    for (let str of A) {
        let tmpArr = new Array(26).fill(0);
        str.split("").forEach((v) => {
            tmpArr[v.charCodeAt() - 'a'.charCodeAt()]++;
        })
        for(let i = 0; i < 26; i++){
            arr[i] = Math.min(arr[i], tmpArr[i]);
        }
    }
    let res = [];
    for (let i = 0; i < 26; i++) {
        for (let k = 0; k < arr[i]; k++) {
            res.push(String.fromCharCode(i + 'a'.charCodeAt()));
        }
    }
    return res;
}
```
方法三：简便写法（写法简便，效率不一定）
2019.09.02补充方法3的详细思路：
1. 把A[0]的字符串划分得到的字符串作为结果数组res。
2. 对res进行过滤，具体操作是依次查找res中的各个字符的次数，是否等于分别在A[1]~A[N - 1]中出现的次数，过滤掉次数不同的元素。
3. 对于遍历A[i]~A[N - 1]时，当前的A[k]判断res中的每一个字符是否存在于它，都需要把已经查到的值用真值代替，避免重复判断。
4. 返回过滤后的res。
```
var commonChars = function(A){
    let res = A[0].split("");
    for (let i = 1; i < A.length; i++) {
        let tmp = A[i].split("");
        res = res.filter(e => {
            let index = tmp.indexOf(e);
            return index !== -1 ? tmp[index] = 1 : false
        });
    }
    return res;
}
```

java版，好久没写java了导致写的很丑，这个方法并不会优化效率（甚至还很慢），只是另一种思路
```

public List<String> commonChars(String[] A) {
    if (A.length == 0) {
        return new ArrayList<String>();
    }
    char[] first = A[0].toCharArray();
    List<String> result = new ArrayList<String>();
    for (char c : first) {
        result.add(String.valueOf(c));
    }
    for (int i = 1; i < A.length; i++) {
        char[] tmp = A[i].toCharArray();
        result = result.stream().filter(c -> find(tmp, c)).collect(Collectors.toList());
    }
    return result;
}
	
private boolean find(char[] str, String c) {
    for (int i = 0; i < str.length; i++) {
        if (str[i] == c.charAt(0)) {
            str[i] = '#';
            return true;
        }
    }
    return false;
}

```