#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
typedef unsigned int uint;

enum ctype {
	WARRIOR = 00,
	WIZARD = 01,
	ARCHER = 10,
	PRIEST = 11
};

typedef struct {
	char name[1000];

	union {
		uint id;
		struct {
			uint idType : 2;
		};
	};

	union {
		uint level;
	};

	union {
		uint hp;
		struct {
			uint hpType : 2;
		};
	};

}character;
//int setCharInfo(character* _char) {
//	uint type;
//
//
//	return 0;
//}


int levelUp(character* _char) {
	_char->level++;
	_char->hp = _char->hp * 1.1;

	return 0;
}

//void printCharInfo(character* _char) {
//	//uint type;
//
//
//	printf("[Name] %s [ID] %u [%s, Lv.%d] [HP] %u", _char->name, _char->id, _char->idType, _char->level, _char->hp);
//
//	printf("%u \n", _char->abil);
//}


int main() {
	int i;
	character user = { 0 };//error

	//setCharInfo(&user);
//	printCharInfo(&user);
	for (i = 0; i < 5; i++) {
		levelUp(&user);
		//printCharInfo(&user);
	}
	return 0;
}
//ref . https://dojang.io/mod/page/view.php?id=454