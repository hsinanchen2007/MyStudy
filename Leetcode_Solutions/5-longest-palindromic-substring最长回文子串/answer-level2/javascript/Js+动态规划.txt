/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(s.length===0) {
        return ""
    }
    if(s.length===1) {
        return s
    }
    /*动态规划
    定义两个指针left、right。
    从两边开始判断，如果两边字符相同且中间字符小于两个（一个或者0个都构成回文），则此子段构成回文；
                   若中间字符>=两个，则要判断中间的子段是否是回文。
    由于是从左到右循环，abba为例，判断依次为ab,abb,bb，abba,当判断abba时中间的子段bb已经在之前判断过。
    循环两次，时间复杂度为O(n2)；一个二维数组，空间复杂度为O(n2)
    JS作为脚本语言很容易超时，可以把超时的测试用例拿过来删减点测试，一步步减掉时间。
    */
    var arr = []
    var max = 0
    var ret = ''
    for(let left=0; left < s.length; left++) { 
            arr[left] = []
    }
    for(let right=1; right < s.length; right++) {
        for(let left=0; left < right; left++) {
            if((s.charAt(left)===s.charAt(right)) && (right-left<=2 || arr[left+1][right-1] )) {
                arr[left][right] = true  
                if(right-left+1 > max) {
                    max = right-left+1
                    ret = s.slice(left,right+1)
                }
            }
        }
    }
    if(max === 0) {
        return s.charAt(0)
    }
    return ret
};