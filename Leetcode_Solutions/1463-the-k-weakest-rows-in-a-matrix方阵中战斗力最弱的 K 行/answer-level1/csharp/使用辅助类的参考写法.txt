```

public class Solution {
       
 //使用类绑定行号和个数`内联代码`
        class ArmCount:IComparable
    {
        int count;
        int rowIndex;

        public ArmCount()
        {
            count = 0;
            rowIndex = 0;
        }

        public int Count { get => count; set => count = value; }
        public int RowIndex { get => rowIndex; set => rowIndex = value; }

        public int CompareTo(object obj)
        {
        {
            //比较结果
            //1  大于，在后
            //0  等于
            //-1 小于
        switch(((ArmCount)obj).Count == this.Count)
            {
                case true:
                    return RowIndex.CompareTo(((ArmCount)obj).RowIndex);
                case false:
                    {
                        if (((ArmCount)obj).Count > this.Count)
                            return -1;
                        else
                            return 1;
                    }
                default:
                return 0;

            }
        }
        }
    }
    public int[] KWeakestRows(int[][] mat, int k) {

        int[] result=new int[k];
        ArmCount[] arm = new ArmCount[mat.Length];
        int row = mat.Length;
        int column = mat[0].Length;



        //获取每行1的个数
        for(int row_index = 0; row_index < row; row_index++)
        {
                arm[row_index] = new ArmCount();
            for (int column_index = 0; column_index < column; column_index++)
            {
                if (mat[row_index][column_index]==1)
                {
                    arm[row_index].Count++;
                }
            }
                arm[row_index].RowIndex = row_index;
            }
            // Array.Sort(students, (s1, s2) => s1.Score.CompareTo(s2.Score));
            Array.Sort(arm);

        //排序完成，输出前k个非空数据
        
        for(int index = 0,activeIndex=0 ; activeIndex < k&&index<100; index++)
            {
                if (arm[index] == null)
                    continue;
                result[activeIndex] = arm[index].RowIndex;
                activeIndex++;

            }



        return result;
    }
}


```
