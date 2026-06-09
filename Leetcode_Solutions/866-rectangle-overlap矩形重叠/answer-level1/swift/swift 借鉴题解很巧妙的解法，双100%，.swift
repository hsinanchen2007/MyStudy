   
    从相反的角度去考虑,整理出两个矩形不重叠的四种情况,分别为rec1在rec2的左上右下,满足不重叠
![WechatIMG50.jpeg](https://pic.leetcode-cn.com/b32d7449237038cf93e7269e60ee8cd73f11d7de6909e4b211c5c4b12ba017e1-WechatIMG50.jpeg)


     class Solution {
        func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
            if (rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[0] >= rec2[2] || rec1[3] <= rec2[1]){
                return false
            }else{
                return true
            }
        }
    }