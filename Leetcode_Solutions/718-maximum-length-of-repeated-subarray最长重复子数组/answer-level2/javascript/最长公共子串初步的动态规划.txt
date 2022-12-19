```
function LCS(str1, str2){
    console.log(str1);
    console.log(str2);

    let maxLen = 0;
    let index_i = 0;
    let index_j = 0;

    //构建二维数组
    let arr = new Array();
    for (let i = 0; i < str1.length; i ++) {
        arr[i] = new Array();
        for (let j = 0; j < str2.length; j ++) {
            arr[i][j] = 0;
        }
    }
    //暴力解法是从字符串开端开始找寻，现在换个思维考虑以字符结尾的子串来利用动态规划法。
    //用dp[i][j]表示以 A[i]和B[j]为结尾的相同子串的最大长度
    //i 是 纵坐标,  j 是横坐标
    for(let i = 0; i < str1.length; i ++){
        for(let j = 0; j < str2.length; j ++){
            if (i == 0 || j == 0 ) {
                //这个主要是边界问题
                if (str1[i] == str2[j]) {
                    //存储这个时候的 最大公共子串的长度;
                    arr[i][j] = 1; 
                };
            } else {
                //如果还相等, 就为 i j 各减一, 就是str1 和 str2 出上一处
                //公共子串的最大长度 的 基础上 再加一;
                if (str1[i] == str2[j]) {
                    arr[i][j] = arr[i - 1][j - 1] + 1; 
                }
            };
            if(arr[i][j] > maxLen){
                maxLen = arr[i][j];
                index_i = i;
            };
        }
    }


    let str = "";
    for(let k = index_i - maxLen + 1; k <= index_i; k ++){
        str += str1[k];
    }
    console.log('str:', str);
    return maxLen;
}

```
