```
public static int NumberOfBoomerangs(int[][] points)
        {
            int res = 0;
            for(int i = 0; i < points.Length; i++)
            {
                Dictionary<int,int> set = new Dictionary<int,int>();
                for(int j = 0; j < points.Length; j++)
                {
                    if (i != j)
                    {
                        int k = Distance(points[i], points[j]);

                        if (set.Keys.Contains(k))
                        {
                            set[k] += 1;
                        }else
                        {
                            set[k] = 1;
                        }
                        
                    }
                }

                foreach(var keyValue in set) {
                    res += keyValue.Value * (keyValue.Value - 1);
                }

            }
            return res;
        }
private static int Distance(int[] a,int[] b)
        {
            return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
        }
```
