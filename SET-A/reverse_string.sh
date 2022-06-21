read -p "Enter String: " input
reverse=""
len=${#input}

for (( i=$len-1; i>=0; i-- ))
do
reverse="$reverse${input:$i:1}"
done

echo "reverse of $input is $reverse"