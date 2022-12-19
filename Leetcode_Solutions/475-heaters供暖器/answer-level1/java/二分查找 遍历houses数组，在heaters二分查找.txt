```
        int []res = new int[houses.length];
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int left = 0;
        int right = 0;
        for (int i=0;i<houses.length;i++){
             left = 0;
             right = heaters.length-1;
             while (left < right){
                int mid = (left + right) >>1;
                if (heaters[mid] < houses[i])
                    left = mid+1;
                else if (heaters[mid] > houses[i])
                    right = mid-1;
                else
                    break;
            }
            if(heaters[left] == houses[i])
                res[i] = 0;
            else if (heaters[left] > houses[i]){
                if (left !=0 )
                    res[i] = heaters[left] - houses[i] < houses[i] - heaters[left-1]?
                            heaters[left] - houses[i]:houses[i] - heaters[left-1];
                else 
                    res[i] = heaters[left] - houses[i];
            }
            else {
                if (left != heaters.length-1 )
                    res[i] = houses[i] - heaters[left] < heaters[left+1] - houses[i] ?
                            houses[i] - heaters[left]:heaters[left+1] - houses[i];
                else
                    res[i] = houses[i] - heaters[left];
            }

        }
        Arrays.sort(res);
        return res[res.length-1];
```
