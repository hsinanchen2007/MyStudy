```
public int[] FindDiagonalOrder(int[][] matrix) {
            if(matrix==null||matrix.Length==0){
                return new int[]{};
            }
            int h = matrix.Length;
            int w = matrix[0].Length;
            int i = 0, j = 0;
            var list = new List<int>();
            var upper = true;
            while (list.Count <h * w)
            {
                list.Add(matrix[i][j]);
                if (upper)
                {
                    if(i==0){
                        j++;
                        if(j>=w){
                            i++;
                            if(i>=h){
                                i--;
                            }
                            j=w-1;
                        }
                        upper=false;
                    }else if(j==w-1){
                        i++;
                        if(i>=h){
                            break;
                        }
                        upper=false;
                    }
                    else{
                        
                        i--;
                        j++;
                    }
                }
                else
                {
                    if(j==0){
                       i++;
                       if(i>=h){
                           i=h-1;
                           j++;
                           if(j>=w){
                               j--;
                           }
                       }
                       upper=true;
                    }else if(i==h-1){
                        j++;
                        if(j>=w){
                            break;
                        }
                        upper=true;
                    }else{
                        i++;
                        j--;
                    }
                }
            }
            return list.ToArray();
    }
```
