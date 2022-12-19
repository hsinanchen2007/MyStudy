class Solution 
{
    public List<Integer> pathInZigZagTree(int label) 
    {
        List<Integer> list = new LinkedList<>();
        int level=1;
        int num=label;//num用于记载label在正常二叉树中的位置；
        for(;;level++)
        {
            if(label<(1<<level))//找到其所在层数；
                break;
        }
        if(0==(level%2))//如果一进去就是偶数层，由非正常序号找到正常序号；
        {
            list.add(0,label);
            num=3*(1<<(level-1))-1-label;//正常二叉树的位置；
            label=num/2;
            num/=2;
            level--;
        }
        for(;level>=1;level--)
        {
            if(0==(level%2))//如果是偶数层，由正常序号找到非正常序号，即题目要求的序号；
            {
                label=3*(1<<(level-1))-1-num;
            }
            else
                label=num;
            list.add(0,label);
            num/=2;
        }
        return list;