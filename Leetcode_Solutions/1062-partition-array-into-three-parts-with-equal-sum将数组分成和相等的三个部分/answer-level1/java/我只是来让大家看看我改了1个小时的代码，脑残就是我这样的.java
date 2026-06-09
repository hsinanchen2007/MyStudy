public boolean canThreePartsEqualSum(int[] A) {
			Map numMap=new HashMap<Integer,Object>();//key:和值   value：当前坐标的合集
			int sum=0;
			for(int i=0;i<A.length;i++) {
				sum=sum+A[i];
				if(numMap.get(sum)==null) {
					numMap.put(sum, i);
				}else {
					Object obj = numMap.get(sum);
					if(obj instanceof Integer) {
						List<Integer> distinceList=new ArrayList<Integer>();
						distinceList.add((int)obj);
						distinceList.add(i);
						numMap.put(sum, distinceList);
					}else {//本来就是List<Integer>
						((List<Integer>)obj).add(i);
					}
				}
			}
			if(sum%3!=0) {
				return false;//无法三等分
			}
			int avg=sum/3;//三等分数
			Object onePassThree = numMap.get(avg);
			Object twoPassThree = numMap.get(2*avg);
			if(onePassThree==null||twoPassThree==null) {
				return false;
			}
			if(onePassThree instanceof Integer&&twoPassThree instanceof Integer) {
				if((int)onePassThree< (int)twoPassThree&&(int)twoPassThree!=A.length-1) {
					return true;
				}else {
					return false;
				}
			}else if(onePassThree instanceof List&&twoPassThree instanceof Integer){
				if(((int)((List)onePassThree).get(0))<(int)twoPassThree&&(int)twoPassThree!=A.length-1) {
					return true;
				}else {
					return false;
				}
			}else if(onePassThree instanceof Integer&&twoPassThree instanceof List){
				((List<Integer>)twoPassThree).remove((Object)(A.length-1));
				((List<Integer>)twoPassThree).remove((Object)(onePassThree));
				if(((List<Integer>)twoPassThree).size()!=0&&(int)onePassThree<(int)((List<Integer>)twoPassThree).get(((List<Integer>)twoPassThree).size()-1)) {
					return true;
				}else {
					return false;
				}
			}else {
				((List<Integer>)twoPassThree).remove((Object)(A.length-1));
				((List<Integer>)twoPassThree).remove((Object)(((List<Integer>)onePassThree).get(0)));
				if(((List<Integer>)twoPassThree).size()!=0&&(int)((List<Integer>)onePassThree).get(0)<(int)((List<Integer>)twoPassThree).get(((List<Integer>)twoPassThree).size()-1)) {
					return true;
				}else {
					return false;
				}
			}
	}