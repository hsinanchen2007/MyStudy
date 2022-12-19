```
 public int minimumLengthEncoding(String[] words) {
		 PriorityQueue<String> queue = new PriorityQueue<String>(new Comparator<String>() {

				@Override
				public int compare(String o1, String o2) {
					// TODO Auto-generated method stub
					return o2.length() - o1.length();
				}
			});
			
			
			ArrayList<String> other = new ArrayList<String>();
			for (int i = 0; i < words.length; i++) queue.offer(words[i]);
			while (!queue.isEmpty()) {
				other.add(queue.poll());
			}
			for (int i = 0; i < other.size(); i++) System.out.println(other.get(i));
			int i = 0 , j = other.size() - 1;
			while (!other.isEmpty() && i < other.size()) {
				while (j > i) {
					if(other.get(i).endsWith(other.get(j))) {
						other.remove(j);
					}
					j--;
				}
				j = other.size() - 1;
				i++;
			}
			System.out.println("other size:"+other.size());
			int sum = 0;
			for (int k = 0; k < other.size(); k++) sum += (other.get(k).length() + 1);
			return sum;
	        
	 }
```
