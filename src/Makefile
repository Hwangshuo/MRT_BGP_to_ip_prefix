CXX = g++
bgp_dump_data =  ../data/bgpdump_data.txt
ipv4_FIB =  ../data/ipv4_FIB.txt
.PHONY:get_FIB check_FIB

get_FIB:
	$(CXX)  get_FIB.cpp -o get_FIB
	./get_FIB  $(bgp_dump_data)
check_FIB:
	$(CXX)  check_FIB.cpp -o check_FIB
	./check_FIB $(ipv4_FIB)
clean:
	rm -f get_FIB
	rm -f check_FIB