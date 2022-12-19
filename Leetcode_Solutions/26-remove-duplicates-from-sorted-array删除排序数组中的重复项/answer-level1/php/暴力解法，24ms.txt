基于有序数组，我们用一个循环就可以解决。
把每一个元素和下一个进行比较，如果相同就unset掉当前元素。
function removeDuplicates(&$nums) {
        $len = count($nums);
        for($i=0;$i<$len-1;$i++)
        {
            if($nums[$i] == $nums[$i+1])
            {
                unset($nums[$i]);
            }
        } 
        return count($nums);
    }