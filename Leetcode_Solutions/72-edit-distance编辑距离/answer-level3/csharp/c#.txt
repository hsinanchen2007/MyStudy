public class MinDistance
    {
        private int[,] data;
        private char[] ca;
        private char[] cb;

        public async Task<int[,]> CreateArray(string a,string b)
        {
            data = new int[a.Length + 1, b.Length+1];
            for (int i = 0; i < a.Length+1; i++)
            {
                data[i, 0] = i; 
            }
            for (int i = 1; i < b.Length + 1; i++)
            {
                data[0, i] = i;
            }
            ca = a.ToCharArray();
            cb = b.ToCharArray();
            return data;
        }


        public async Task<int> Min()
        {
            //min(data[n,n-1]+1,data[n-1,n]+1, data[n-1,n-1]) 最后位相等
            //min(data[n,n-1]+1,data[n-1,n]+1, data[n-1,n-1]) 最后位不相等
            for (int row = 1; row < data.GetLength(0); row++)
            {
                for (int col = 1; col < data.GetLength(1); col++)
                {
                    var num = data[row - 1, col - 1];
                    if (ca[row - 1] != cb[col - 1])
                    {
                        num += 1;
                    }
                    var list= new int[]{ num, data[row, col - 1] + 1, data[row-1, col] + 1};
                    data[row, col] = list.Min();
                }
            }
            return data[data.Rank,data.GetLength(0)];
        }
    }