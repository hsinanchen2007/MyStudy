用时68ms，内存33.7MB，战胜96.47%（别在意这个百分比，跟算法关系不大。。。）
没看到有js的解，简单说一下。(其实是直接搜索js没搜到，懒死我算了)
var plusOne = function(digits) {
    let p = digits.length - 1; 
    digits[p]++;//最后一位+1
    for(let i in digits){
        if((digits[p-i]) == 10){//如果进位
            digits[p-i] = 0;//归零
            if(p-i == 0){//如果当前位已经是0了
                digits.unshift(1);//前面加个1
                return digits;
            }
            digits[p-i-1]++;下一位进位；
        }
    }
    return digits;
};
整体思路是正面刚，从后往前循环每一位，如果进位就当前为归零，前一位+1.