# 解题思路
## 两种方法解决
## 方法一回溯法
1. 分析思路：用回溯法解问题时，应明确定义问题的解空间。问题的解空间至少包含问题的一个（最优）解。n对括号总共有2n个单括号 能形成长度2n的向量，向量中取值为'('和')'。由此可知解空间是一个二叉树。
2. 优化剪枝：
- 初始左括号数=右括号数=n，用LR=[n,n]记录左右括号当前的数目。
- 每次向左走，LR[0]--。每次向右走，LR[1]--。当n都减少到0时结束。回溯
- LR[0]>LR[1]时，会导致后面的左括号多余右括号。最终括号不匹配。应该剪枝
3. 借用下他人配图解释
![回溯解决n对括号的所有结果.png](https://pic.leetcode-cn.com/763d20e9f353474a353d6a3d622e9f5e06af10eba98183cabb89ea902ad6c67d-%E5%9B%9E%E6%BA%AF%E8%A7%A3%E5%86%B3n%E5%AF%B9%E6%8B%AC%E5%8F%B7%E7%9A%84%E6%89%80%E6%9C%89%E7%BB%93%E6%9E%9C.png)


## 方法二动态规划
1. 构造模型
F(n)   return得到n个括号的所有括号组合数组
2. 分析它的子问题得到状态转移方程
- 前一个阶段所有子问题：用最后一对'()'括住前k个括号，再拼接剩下n-1-k个括号的组合。得到F(k).length*F(n-1-k).length个结果。由于最后一对括号可以有n种打括号的方法。
所有结果数：(k:0->n-1)∑ F(k).length*F(n-1-k).length

F(n) = ∑ '('+F(k)+')' +  F(n-1-k) 

# 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {   
    /**
     * ******动态规划和回溯法的子函数******
     *         **     **           
     *        *****************      
     *      **        **             
     *    **          **          
     *      *********************     
     *             ** ** **          
     *            **  **  **            
     *           **   **   **          
     *          **    **    **          
     *         **     **     **    
     * ******动态规划和回溯法的子函数******
     */



    // 动态规划法 模型方程
    /**F(n) =  for(k:0 -> n-1){ arr.push( '('+F(k)+')' +  F(n-1-k) ) }
     * @param {number} n
     * @return {string[]}
     */
    function F(n){
        if(list[n]){
            return list[n]
        }
        if(n==0 || n==1){
            list[0] = [''];
            list[1] = ['()']
            return list[n];
        }
        var result = [];
        for(let i = 0; i<=n-1; i++){ //最后一对括号的 需要括的括号数目
            let preF = F(i);
            let aftF = F(n-1-i);
            for(let k=0;k<preF.length;k++){
                let currentPre = '('+preF[k]+')';                
                for(let j=0; j<aftF.length; j++){ //括了i个括号后，剩余n-1-i个括号需要组合
                    result.push(currentPre+aftF[j]);
                }
            }           
        }
        list[n] = result;
        return list[n];
    }
    // 回溯法方程
    /**trackback()
     * @param {number} n
     * @return {string[]}
     */
    function trackback(n) {
    var LR = [n, n] //存剩余的左右括号个数
    var result = bracket(LR, '');
    /**bracket(LR)
     * @param {number[]} LR
     * @param {string} current 下一层的选择
     * @return {string[]} 存放从叶子节点到该层的 拼接的括号 组  
     */
    function bracket(LR, current) {
      var currentLR = [...LR];
      var LeftArr = [];
      var rightArr = [];
      if (currentLR[0] > currentLR[1]) {
        return [];
      } else if (currentLR[1] == 0) {
        return [')']
      } else {
        if (currentLR[0] == 0) {
          //左边为0，右边不为0 向右→走
          currentLR[1]--;
          rightArr = bracket(currentLR, ')');
          for (let i = 0; i < rightArr.length; i++) {
            rightArr[i] = current + rightArr[i]
          }
          return rightArr
        } else {
          //左边右边都不为0
          currentLR[0]--;
          LeftArr = bracket(currentLR, '(');
          for (let i = 0; i < LeftArr.length; i++) {
            LeftArr[i] = current + LeftArr[i]
          };
          currentLR[0]++;
          currentLR[1]--;
          rightArr = bracket(currentLR, ')');
          for (let i = 0; i < rightArr.length; i++) {
            rightArr[i] = current + rightArr[i]
          }
          return LeftArr.concat(rightArr);
        }
      }
    }
    return result;
  }










    //动态规划法：
    var list = new Array(n+1); //记录F(0)->F(n)的结果 每项都是 string[]。避免重复计算提高效率
    var result = F(n);
    return result;
    // 回溯法
    // var trackbackResult = trackback(n);    
    // return trackbackResult
};
```