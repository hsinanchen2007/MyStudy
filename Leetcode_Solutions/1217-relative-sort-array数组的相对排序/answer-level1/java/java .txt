class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] a=new int[arr1.length];
       LinkedList<Integer> b=new LinkedList<>();
        for(Integer s:arr2)
            b.add(s);
        HashMap<Integer,Integer> c=new HashMap<>();
        for(Integer s:arr1)
        {
            if(c.containsKey(s))
                c.put(s,c.get(s)+1);
            else
                c.put(s,1);
        }
        int i=0;
      while(i<arr1.length)
        {
            int temp=b.poll();
            while(c.containsKey(temp)&&c.get(temp)>0)
            {
                a[i]=temp;
                i++;
                c.put(temp,c.get(temp)-1);
            }
          if(b.size()==0)
              break;
        }
        int j=i;
        for(Integer s:arr1)
        {
            while(c.get(s)>0)
            {
                a[i++]=s;
                c.put(s,c.get(s)-1);
            }
        }
        Arrays.sort(a,j,arr1.length);
        return a;
       
    }
}