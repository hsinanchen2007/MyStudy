方式一：双指针，遍历数组，等于右指针的时候更新left和right，然后更新每个字母的相对位置
var shortestToChar = function(S, C) {
    let result = new Array(S.length);
    let left = S.indexOf(C);
    let right = S.indexOf(C, left + 1);
    for(let index = 0; index < S.length; index ++)
    {
        if(index == right)
        {
            result[index] = 0;
            left = right;
            right = S.indexOf(C, left + 1);
        }
        else
        {
            if(right == -1)
            {
                result[index] = Math.abs(index - left);
            }
            else
            {
                result[index] = Math.min(Math.abs(index - left), right - index);
            }
        }
    }
    return result;
};

方法二：用object记录每个目标字符的位置，然后遍历数组，更新每个字符的相对位置
var shortestToChar = function(S, C) {
    let arrMap = {};
    let index = 0;
    for(let i = 0; i < S.length; i ++)
    {
        if(S[i] == C)
        {
            arrMap[index ++] = i;
        }
    }
    let result = new Array(S.length);
    result.fill(100000);
    for(let i = 0; i <S.length; i ++)
    {
        for(let key in arrMap)
        {
            let num = Math.abs(i - arrMap[key]);
            if(result[i] > num)
            {
                result[i] = num;
            }
        }
    }
    return result;
};