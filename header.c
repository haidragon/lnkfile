#include <wuzdef.h>

/** The type of ShellLinkHeader and its pointer type.
*  The ShellLinkHeader type is an alias from the structure tagShellLinkHeader.
* @{
*/
typedef struct tagLNK_OBJECT LNKOBJ, *PLNKOBJ;
typedef struct tagShellLinkHeader ShellLinkHeader, *PShellLinkHeader;

typedef struct tagItemIDList ItemIDList, *PItemIDList;
typedef struct tagTargetIDList TargetIDList, *PTargetIDList;

typedef struct tagLinkInfo LinkInfo, *PLinkInfo;
typedef struct tagVolumeID VolumeID, *PVolumeID;

/** @}*/

/** A structure tagShellLinkHeader.
*  The ShellLinkHeader structure contains identification information,
*  timestamps, and flags that specify the presence of optional structures.
*/
#ifdef __TINYC__
__attribute__((aligned(8), packed))
#endif

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif
struct tagShellLinkHeader
{
	uint32_t size; /**< The size, in bytes, of this structure. This value MUST be 0x0000004C. */
	GUID clsid;    /**< A class identifier (CLSID). This value MUST be 00021401-0000-0000-C000-000000000046*/
	uint32_t
		flag,        /**< A LinkFlags structure that specifies information about the shell link and the
					 *   presence of optional portions of the structure.
					 *   The LinkFlags structure defines bits that specify which shell link structures are
					 *   present in the file format after the ShellLinkHeader structure:
					 *  @tableofcontents
					 *  |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|
					 *  |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
					 *  |A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|AA| | | | | |
					 *  Where the bits are defined as:
					 *  - A @b HasLinkTargetIDList The shell link is saved with an item ID list (IDList).
					 *         If this bit is set, a LinkTargetIDList structure MUST follow the
					 *         ShellLinkHeader.
					 *  - B @b HasLinkTargetIDList The shell link is saved with link information. If this bit
					 *         is set, a LinkInfo structure MUST be present.
					 *  - C @b HasName The shell link is saved with a name string. If this bit is set, a
					 *         NAME_STRING StringData structure MUST be present.
					 *  - D @b HasRelativePath The shell link is saved with a relative path string. If this bit
					 *         is set, a RELATIVE_PATH StringData structure MUST be present.
					 *  - E @b HasWorkingDir The shell link is saved with a working directory string. If this bit
					 *         is set, a WORKING_DIR StringData structure MUST be present.
					 *  - F @b HasArguments The shell link is saved with command line arguments. If this bit is
					 *         set, a COMMAND_LINE_ARGUMENTS StringData structure MUST be present.
					 *  - G @b HasIconLocation The shell link is saved with an icon location string. If this bit
					 *         is set, an ICON_LOCATION StringData structure MUST be present.
					 *  - H @b IsUnicode The shell link contains Unicode encoded strings. This bit SHOULD be set.
					 *  - I @b ForceNoLinkInfo The LinkInfo structure is ignored.
					 *  - J @b HasExpString The shell link is saved with an EnvironmentVariableDataBlock.
					 *  - K @b RunInSeparateProcess The target is run in a separate virtual machine when launching
					 *         a link target that is a 16-bit application.
					 *  - L @b Unused1 A bit that is undefined and MUST be ignored.
					 *  - M @b HasDarwinID The shell link is saved with a DarwinDataBlock.
					 *  - N @b RunAsUser The application is run as a different user when the target of the shell
					 *         link is activated.
					 *  - O @b HasExpIcon The shell link is saved with an IconEnvironmentDataBlock.
					 *  - P @b NoPidlAlias The file system location is represented in the shell namespace when the
					 *         path to an item is parsed into an IDList.
					 *  - Q @b Unused2 A bit that is undefined and MUST be ignored.
					 *  - R @b RunWithShimLayer The shell link is saved with a ShimDataBlock.
					 *  - S @b ForceNoLinkTrack The TrackerDataBlock is ignored.
					 *  - T @b EnableTargetMetadata The shell link attempts to collect target properties and store
					 *         them in the PropertyStoreDataBlock when the link target is set.
					 *  - U @b DisableLinkPathTracking The EnvironmentVariableDataBlock is ignored.
					 *  - V @b DisableKnownFolderTracking The SpecialFolderDataBlock and the KnownFolderDataBlock are
					 *         ignored when loading the shell link. If this bit is set, these extra data blocks SHOULD
					 *         NOT be saved when saving the shell link.
					 *  - W @b DisableKnownFolderAlias If the link has a KnownFolderDataBlock, the unaliased form of
					 *         the known folder IDList SHOULD be used when translating the target IDList at the time
					 *         that the link is loaded.
					 *  - X @b AllowLinkToLink Creating a link that references another link is enabled. Otherwise,
					 *         specifying a link as the target IDList SHOULD NOT be allowed.
					 *  - Y @b UnaliasOnSave When saving a link for which the target IDList is under a known folder,
					 *         either the unaliased form of that known folder or the target IDList SHOULD be used.
					 *  - Z @b PreferEnvironmentPath The target IDList SHOULD NOT be stored; instead, the path
					 *         specified in the EnvironmentVariableDataBlock SHOULD be used to refer to the target.
					 *  - AA @b KeepLocalIDListForUNCTarget When the target is a UNC name that refers to a location
					 *         on a local machine, the local path IDList in the PropertyStoreDataBlock SHOULD be stored,
					 *         so it can be used when the link is loaded on the local machine.
					 */
		attr;        /**<  A FileAttributesFlags structure that specifies information about the link target.
					 *    The FileAttributesFlags structure defines bits that specify the file attributes of the link
					 *    target, if the target is a file system item. File attributes can be used if the link target
					 *    is not available, or if accessing the target would be inefficient. It is possible for the
					 *    target items attributes to be out of sync with this value.
					 *  @tableofcontents
					 *  |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|
					 *  |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
					 *  |A|B|C|D|E|F|G|H|I|J|K|L|M|N|O| | | | | | | | | | | | | | | | | |
					 *  Where the bits are defined as:
					 *  - A @b FILE_ATTRIBUTE_READONLY The file or directory is read-only. For a file, if this bit is
					 *         set, applications can read the file but cannot write to it or delete it. For a directory,
					 *         if this bit is set, applications cannot delete the directory.
					 *  - B @b FILE_ATTRIBUTE_HIDDEN The file or directory is hidden. If this bit is set, the file or
					 *         folder is not included in an ordinary directory listing.
					 *  - C @b FILE_ATTRIBUTE_SYSTEM The file or directory is part of the operating system or is used
					 *         exclusively by the operating system.
					 *  - D @b Reserved1 A bit that MUST be zero.
					 *  - E @b FILE_ATTRIBUTE_DIRECTORY The link target is a directory instead of a file.
					 *  - F @b FILE_ATTRIBUTE_ARCHIVE The file or directory is an archive file. Applications use this
					 *         flag to mark files for backup or removal.
					 *  - G @b Reserved2 A bit that MUST be zero.
					 *  - H @b FILE_ATTRIBUTE_NORMAL The file or directory has no other flags set. If this bit is 1,
					 *         all other bits in this structure MUST be clear.
					 *  - I @b FILE_ATTRIBUTE_TEMPORARY The file is being used for temporary storage.
					 *  - J @b FILE_ATTRIBUTE_SPARSE_FILE The file is a sparse file.
					 *  - K @b FILE_ATTRIBUTE_REPARSE_POINT The file or directory has an associated reparse point.
					 *  - L @b FILE_ATTRIBUTE_COMPRESSED The file or directory is compressed. For a file, this means
					 *         that all data in the file is compressed. For a directory, this means that compression
					 *         is the default for newly created files and subdirectories.
					 *  - M @b FILE_ATTRIBUTE_OFFLINE The data of the file is not immediately available.
					 *  - N @b FILE_ATTRIBUTE_NOT_CONTENT_INDEXED The contents of the file need to be indexed.
					 *  - O @b FILE_ATTRIBUTE_ENCRYPTED The file or directory is encrypted. For a file, this means that
					 *         all data in the file is encrypted. For a directory, this means that encryption is the
					 *         default for newly created files and subdirectories.
					 */
	FILETIME
		create1,      /**<  A FILETIME structure that specifies the creation time of the link target in UTC (Coordinated
					  *    Universal Time). If the value is zero, there is no creation time set on the link target.
					  */
		access1,      /**<  A FILETIME structure that specifies the access time of the link target in UTC (Coordinated
					  *    Universal Time). If the value is zero, there is no access time set on the link target.
					  */
		write1;       /**<  A FILETIME structure that specifies the write time of the link target in UTC (Coordinated
					  *    Universal Time). If the value is zero, there is no write time set on the link target.
					  */
	uint32_t
		fsize,       /**<  A 32-bit unsigned integer that specifies the size, in bytes, of the link target. If the link
					 *    target file is larger than 0xFFFFFFFF, this value specifies the least significant 32 bits of
					 *    the link target file size.
					 */
		icon,        /**<  A 32-bit signed integer that specifies the index of an icon within a given icon location. */
		cmd;         /**<  A 32-bit unsigned integer that specifies the expected window state of an application launched
					 *    by the link. This value SHOULD be one of the following.
					 *  @tableofcontents
					 *  |Value|Meaning|
					 *  |-----|-------|
					 *  |@b SW_SHOWNORMAL<BR>0x00000001|The application is open and its window is open in a normal fashion.|
					 *  |@b SW_SHOWMAXIMIZED<BR>0x00000003|The application is open, and keyboard focus is given to the application, but its window is not shown.|
					 *  |@b SW_SHOWMINNOACTIVE<BR>0x00000007|The application is open, but its window is not shown. It is not given the keyboard focus.|
					 */
	uint16_t
		hotkey,      /**<  A HotKeyFlags structure that specifies the keystrokes used to launch the application referenced
					 *    by the shortcut key. This value is assigned to the application after it is launched, so that
					 *    pressing the key activates that application.<BR>
					 *  @b HotKeyFlags
					 *    The HotKeyFlags structure specifies input generated by a combination of keyboard keys being
					 *    pressed.<BR>
					 *  @b LowByte(0-7bits) An 8-bit unsigned integer that specifies a virtual key code that corresponds to
					 *    a key on the keyboard. This value MUST be one of the following:
					 *  @tableofcontents
					 *  |Value|Meaning|
					 *  |-----|-------|
					 *  |0x30|"0" key|
					 *  |0x31|"1" key|
					 *  |0x32|"2" key|
					 *  |0x33|"3" key|
					 *  |0x34|"4" key|
					 *  |0x35|"5" key|
					 *  |0x36|"6" key|
					 *  |0x37|"7" key|
					 *  |0x38|"8" key|
					 *  |0x39|"9" key|
					 *  |0x41|"A" key|
					 *  |0x42|"B" key|
					 *  |0x43|"C" key|
					 *  |0x44|"D" key|
					 *  |0x45|"E" key|
					 *  |0x46|"F" key|
					 *  |0x47|"G" key|
					 *  |0x48|"H" key|
					 *  |0x49|"I" key|
					 *  |0x4A|"J" key|
					 *  |0x4B|"K" key|
					 *  |0x4C|"L" key|
					 *  |0x4D|"M" key|
					 *  |0x4E|"N" key|
					 *  |0x4F|"O" key|
					 *  |0x50|"P" key|
					 *  |0x51|"Q" key|
					 *  |0x52|"R" key|
					 *  |0x53|"S" key|
					 *  |0x54|"T" key|
					 *  |0x55|"U" key|
					 *  |0x56|"V" key|
					 *  |0x57|"W" key|
					 *  |0x58|"X" key|
					 *  |0x59|"Y" key|
					 *  |0x5A|"Z" key|
					 *  |0x70|"F1" key|
					 *  |0x71|"F2" key|
					 *  |0x72|"F3" key|
					 *  |0x73|"F4" key|
					 *  |0x74|"F5" key|
					 *  |0x75|"F6" key|
					 *  |0x76|"F7" key|
					 *  |0x77|"F8" key|
					 *  |0x78|"F9" key|
					 *  |0x79|"F10" key|
					 *  |0x7A|"F11" key|
					 *  |0x7B|"F12" key|
					 *  |0x7C|"F13" key|
					 *  |0x7D|"F14" key|
					 *  |0x7E|"F15" key|
					 *  |0x7F|"F16" key|
					 *  |0x80|"F17" key|
					 *  |0x81|"F18" key|
					 *  |0x82|"F19" key|
					 *  |0x83|"F20" key|
					 *  |0x84|"F21" key|
					 *  |0x85|"F22" key|
					 *  |0x86|"F23" key|
					 *  |0x87|"F24" key|
					 *  |0x90|"NUM LOCK" key|
					 *  |0x91|"SCROLL LOCK" key|
					 *  @b HighByte(8-15bit) An 8-bit unsigned integer that specifies bits that correspond to modifier
					 *  keys on the keyboard. This value MUST be one or a combination of the following:
					 *  |Value|Meaning|
					 *  |-----|-------|
					 *  |0x01|The "SHIFT" key on the keyboard.|
					 *  |0x02|The "CTRL" key on the keyboard.|
					 *  |0x04|The "ALT" key on the keyboard.|
					 */
		res1;        /**<  A value that MUST be zero. */
	uint32_t
		res2,        /**<  A value that MUST be zero. */
		res3;        /**<  A value that MUST be zero. */
};

#ifdef __TINYC__
__attribute__((aligned(8), packed))
#endif

struct tagItemIDList
{
	uint16_t
		size;
	byte data[1];
};

#ifdef __TINYC__
__attribute__((aligned(8), packed))
#endif

struct tagTargetIDList
{
	uint16_t
		size;
	struct tagItemIDList
		itemid[1];
	uint16_t
		termid;  ///< TerminalID
};

#ifdef __TINYC__
__attribute__((aligned(8), packed))
#endif

struct tagVolumeID
{
	uint32_t
		size,
		type,
		sn,
		offset_label,
		offset_label_uni;
	byte data[1];
};

#ifdef __TINYC__
__attribute__((aligned(8), packed))
#endif

struct tagLinkInfo
{
	uint32_t
		size,
		hsize,
		flag,
		offset_vol,
		offset_basepath,
		offset_network,
		offset_pathsuffix,
		offset_basepath_uni,
		offset_pathsuffix_uni;
};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

struct tagLNK_OBJECT
{
	PTargetIDList idlist;
	PLinkInfo linkinfo;

	struct tagShellLinkHeader header;
	byte data[1];
};