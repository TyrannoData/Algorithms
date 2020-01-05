#include <stdio.h>

#define NUM_NODES 10

struct Node {
	int parent;
};

int find(struct Node *nodes, int i)
{
	if (nodes[i].parent == i) return i;
	return nodes[i].parent = find(nodes, nodes[i].parent);
}

void unify(struct Node *nodes, int a, int b)
{
	a = find(nodes, a);
	b = find(nodes, b);
	if (a <= b) nodes[b].parent = a;
	else nodes[a].parent = b;
}

int main()
{
	struct Node nodes[NUM_NODES];
	for (int i = 0; i < NUM_NODES; i++) {
		nodes[i].parent = i;
	}

	unify(nodes, 0, 1);
	unify(nodes, 1, 2);
	printf("[0]: %d\n", nodes[0].parent);
	printf("[1]: %d\n", nodes[1].parent);
	printf("[2]: %d\n", nodes[2].parent);

	unify(nodes, 3, 4);
	unify(nodes, 4, 5);
	printf("[3]: %d\n", nodes[3].parent);
	printf("[4]: %d\n", nodes[4].parent);
	printf("[5]: %d\n", nodes[5].parent);

	unify(nodes, 0, 3);
	printf("[0]: %d\n", nodes[0].parent);
	printf("[3]: %d\n", nodes[3].parent);
	printf("[5]: %d\n", nodes[5].parent);

	find(nodes, 5);
	printf("[5]: %d\n", nodes[5].parent);
	
	return 0;
}
