一：
暴力法：

    var longestPalindrome = function(s) {
    var max = 0;
    var maxSubString = "";
    for(let i=0; i<s.length; i++){
        for(let j=i+1; j<s.length+1; j++){
            if(isPalindrom(s.substring(i,j))){
                if(j-i > max){  // 有更长的，则更新最长子串
                    max = j-i;
                    maxSubString = s.substring(i,j);
                }

            }
        }
    }
    return maxSubString;
    };

    var isPalindrom = function(s){
    var l = s.length;
    var flag = 0;
    for (let i=0; i<l/2; i++){
        if(s[i]!==s[l-1-i]){
            flag = 1;
        }
    }
    if(flag === 1){
        return false;
    }
    return true;
}
测试用例只能过不到一半，时间复杂度O{n<sup>3</sup>}

二： 求最长子串法

    var longestPalindrom1 = function (s) {
    var rev = s.split('').reverse().join('');
    var array = new Array(); // js创建二维数组
    var maxLen = 0; // 存储当前最长回文子串的长度
    var maxEnd = 0; //存储最长回文子串的结尾位置
    for(let x = 0; x < s.length; x++){
        array[x] = new Array();
        for( let y = 0; y < rev.length; y++){
            array[x][y] = 0;
        }
    }
    for(let i = 0; i< s.length; i++){
        var sub = '';
        for(let j = 0; j<rev.length; j++){
            if(s[i] === rev[j]){ // 相等
                if(i===0 || j===0){ // 判断是否是0行或者0列
                    array[i][j] = 1;
                }else {
                    array[i][j] = array[i-1][j-1] + 1;
                }
            }else{ // 不等跳出本次循环
                array[i][j] = 0;
            }

            if(array[i][j] > maxLen){
                sub =  s.substring(i - array[i][j] + 1,i + 1); // 截取最长子串
                if (sub === sub.split('').reverse().join('')){
                    maxLen = array[i][j];
                    maxEnd = i;
                }
            }
        }
        sub = '';
    }
    return s.substring(maxEnd - maxLen + 1,maxEnd + 1);
    }

用例全过，贼耗时，2700ms。时间复杂度O(n<sup>2</sup>)

三：动态规划法

		var longestPalindrome2 = function (s) {
		var maxLen = 1; // 记录最长子串长度
		var start = 0; // 记录最长子串的开始位置
		if(!s){ // s为空字符
				return '';
		}
		var array =new Array();
		for(let x = 0; x < s.length; x++){ // 建立二维数组---表示x到y的子串
				array[x] = new Array();
				for( let y = 0; y < s.length; y++){
						array[x][y] = 0;
				}
		}
		for(let i = 0; i < s.length; i++){ // 一次遍历，初始化状态
				array[i][i] = 1; // 长度为1
				if(s[i] === s[i+1]){ // 长度为2的回文
						array[i][i+1] = 1;
						maxLen = 2;
						start = i;
				}
		}

    for(let l = 3; l <= s.length; l++){ // 从长度为3开始执行状态转移方程
        for(let i = 0; i < s.length + 1 - l; i++){ // i为开始位置
            if(array[i+1][l+i-2] === 1 && s[i] === s[l+i-1]){ // 子串为回文串 && 两头相等
                array[i][l+i-1] = 1;
                maxLen = l; // 记录结果的长度
                start = i; // 记录结果的开始位置
            }
        }
    }
    return s.substring(start,maxLen + start);
}

时间复杂度O(n<sup>2</sup>)，要点在于先初始化状态，设置子串长度为1的和子串长度为2的。之后从子串长度为3的开始，执行状态转移方程

四： 中心扩展法


五：马拉车算法
