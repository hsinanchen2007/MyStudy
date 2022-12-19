Dictionary<int,int> dic = new Dictionary<int,int>();
            for (int i = 0; i < nums.Length; i++) dic.Add(i,nums[i]);//0,4 1,2  2,6
            
            for (int i = 0; i < nums.Length; i++)
            {
                int vv = target - nums[i];
                if (dic.ContainsValue(vv)) 
                {
                    var d = dic.Where(p => p.Value == vv).Select(p => p.Key).Except(new List<int> { i });
                    
                    if(d.Count()>0)
                    {
                        return i < d.ToArray()[0] ? new int[] { i, d.ToArray()[0] } : new int[] { d.ToArray()[0], i };
                    }
                }
            }

            return new int[] { };