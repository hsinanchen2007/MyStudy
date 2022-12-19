#### 方法一：递归
```
class Solution {
    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        if(nums.size == 0){
            return null
        }

        fun trans(nums:IntArray,left:Int,right:Int,parent:TreeNode){
            if(left > right){
                return
            }
            val mid = (left + right) ushr 1
            val `val` = nums[mid]
            val node = TreeNode(`val`)
            if(`val` > parent.`val`){
                parent.right = node
            }else{
                parent.left = node
            }
            trans(nums,left,mid - 1,node)
            trans(nums,mid + 1,right,node)
        }
        val parent = TreeNode(-Integer.MIN_VALUE)
        trans(nums,0,nums.size - 1,parent)
        return parent.right
    }
}
```
