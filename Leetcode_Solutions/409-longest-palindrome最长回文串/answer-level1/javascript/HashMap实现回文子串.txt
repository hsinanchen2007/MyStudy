var longestPalindrome = function (s) {
    var longest = new Map();
    var count = 0;
    for(let i = 0 ;i < s.length ; i++)
    {
        if(longest.get(s[i]) === 0) //如果存在有这个值，就给它删了，count++
        {
            longest.delete(s[i]);
            count++;
        }  
        
        else 
           longest.set(s[i],0);//如果不存在就存进去
    }

    return longest.size === 0 ? count * 2 : count*2+1;//这个回文序列是奇数个就count*2+1，否则就count+2;
};