tail -n +10 file.txt | head -n 1
sed -n '10p' file.txt
awk 'NR==10' file.txt